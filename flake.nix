{
  description = "AtCoder solutions";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
    atcli = {
      url = "github:gesop0n/atcli";
      inputs.nixpkgs.follows = "nixpkgs";
    };
  };

  outputs =
    {
      nixpkgs,
      flake-utils,
      atcli,
      ...
    }:
    flake-utils.lib.eachDefaultSystem (
      system:
      let
        pkgs = import nixpkgs { inherit system; };
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

        # 問題を解くための環境。atcli は別リポジトリの flake から取る。
        # atcli 自体を直しながら使うときは、手元のチェックアウトを差し込む。
        #   nix develop --override-input atcli path:/path/to/atcli
        devShells.default = pkgs.mkShell {
          packages = cppTools ++ [ atcli.packages.${system}.default ];
          shellHook = clangdShellHook;
        };
      }
    );
}
