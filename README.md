# atcoder

AtCoder の C++ 解答を管理するリポジトリ。問題の準備・サンプルテスト・提出は、別リポジトリの CLI [atcli](https://github.com/gesop0n/atcli) で行う。

## セットアップ

Nix flakes を有効にした環境で、リポジトリのルートから次を実行する。

```console
$ git submodule update --init
$ nix develop
```

この shell には GCC 15、clangd とビルド済みの `atcli` が入る。

`atcli` は flake input として参照しているので、新しい版へ上げるときは lock を更新する。

```console
$ nix flake update atcli
```

`atcli` 自体を直しながら動作確認する場合は、手元のチェックアウトを差し込む。

```console
$ nix develop --override-input atcli path:/path/to/atcli
```

## 使い方

コンテストの問題データと、その日の取り組みを作成する。開催中のコンテストは事前に `atcli login` しておく。

```console
$ atcli login
$ atcli new abc300 a c ex
```

取り組みディレクトリでサンプルテストを回し、通ったらコミットして提出する。

```console
$ cd attempts/2026/09/08/abc300/a
$ atcli test
$ atcli commit
$ atcli submit
```

`atcd` によるディレクトリ移動や shell 統合を含め、コマンドの詳細は [atcli の README](https://github.com/gesop0n/atcli#使い方) を参照。

## ディレクトリ

問題ごとに共有するメタデータとテストは `problems/` に置く。

```text
problems/contest/task/
├── meta.toml
└── tests/
    ├── sample-1.in
    └── sample-1.out
```

日付ごとの取り組みは `attempts/` に置く。`attempt.toml` の `problem` は、`problems/` から問題データへの相対パスになる。

```text
attempts/YYYY/MM/DD/contest/task/
├── attempt.toml  # problem = "abc300/a"
└── main.cpp
```

同じ問題へ別の日に取り組む場合、`problems/` のメタデータとテストは再利用し、日付ごとに異なる `main.cpp` と `attempt.toml` を作成する。日付はコンテスト開催日ではなく、`atcli new` を実行して解き始めた日付になる。

| パス | 用途 |
| --- | --- |
| `lib/` | 自作のライブラリ |
| `ac-library/` | [AC Library](https://github.com/atcoder/ac-library)（submodule） |
| `template/main.cpp` | `atcli new` が使う解答の雛形 |
| `atcli.toml` | `atcli` の設定とルートマーカ |
| `compile_flags.txt` | clangd 用の設定 |

`lib/` と `ac-library/` は `atcli.toml` の `include_dirs` に入れてあるので、解答から直接インクルードできる。

ローカルが macOS の場合、コンパイラのメジャーバージョンを合わせても AtCoder の x86_64 Linux 環境を完全には再現していない。
