{
  description = "AtCoder solutions and the atcli workflow tool";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
    rust-overlay = {
      url = "github:oxalica/rust-overlay";
      inputs.nixpkgs.follows = "nixpkgs";
    };
  };

  outputs =
    {
      nixpkgs,
      flake-utils,
      rust-overlay,
      ...
    }:
    flake-utils.lib.eachDefaultSystem (
      system:
      let
        pkgs = import nixpkgs {
          inherit system;
          overlays = [ rust-overlay.overlays.default ];
        };
        rust = pkgs.rust-bin.fromRustupToolchainFile ./tools/atcli/rust-toolchain.toml;
        rustPlatform = pkgs.makeRustPlatform {
          cargo = rust;
          rustc = rust;
        };
        atcli = rustPlatform.buildRustPackage {
          pname = "atcli";
          version = "0.1.0";
          src = pkgs.lib.cleanSource ./tools/atcli;
          cargoLock.lockFile = ./tools/atcli/Cargo.lock;
        };
        atcliApp = {
          type = "app";
          program = "${atcli}/bin/atcli";
          meta.description = "Prepare and locally test AtCoder solutions";
        };
        gcc = pkgs.gcc15;
        clangdWithGcc = pkgs.writeShellScriptBin "clangd" ''
          exec ${pkgs.clang-tools}/bin/clangd \
            --query-driver="${gcc}/bin/g++,/usr/bin/g++" \
            "$@"
        '';
        clangdShellHook = ''
          export PATH="${clangdWithGcc}/bin:$PATH"
        '';
        cppTools = [
          gcc
          clangdWithGcc
        ];
      in
      {
        formatter = pkgs.nixfmt-tree;

        packages = {
          inherit atcli;
          default = atcli;
        };

        apps = {
          atcli = atcliApp;
          default = atcliApp;
        };

        checks.atcli = atcli;

        # 普段問題を解くための環境。atcli 自体はリリースビルド済みのものを使う。
        devShells.default = pkgs.mkShell {
          packages = cppTools ++ [
            atcli
            # NOTE: direnv で rust-analyzer をインストールしている関係で
            # default に rust を追加しないと editor で lsp が動かない
            rust
          ];
          shellHook = clangdShellHook;
        };

        # atcli の開発環境。E2E テストもできるよう C++ toolchain を含める。
        devShells.atcli = pkgs.mkShell {
          packages = cppTools ++ [ rust ];
          shellHook = clangdShellHook;
        };

        # 問題解答環境
        devShells.work = pkgs.mkShell {
          packages = cppTools ++ [ atcli ];
          shellHook = clangdShellHook;
        };
      }
    );
}
