# atcoder

AtCoder の C++ 解答と、準備・サンプルテストを行う Rust 製 CLI `atcli` を管理するリポジトリ。提出機能は持たない。

## セットアップ

Nix flakes を有効にした環境で、リポジトリのルートから次を実行する。

```console
$ git submodule update --init
$ nix develop
```

この shell には GCC 15、clangd とビルド済みの `atcli` が入る。`atcli` 自体を変更するときは、Rust toolchain も入る開発 shell を使う。

```console
$ nix develop .#atcli
$ cargo test --manifest-path tools/atcli/Cargo.toml
```

## 使い方

コンテストの全問題を、コマンドを実行した日付の下に作成する。

```console
$ atcli new abc300
# 例: 2026/09/09/abc300/{a,b,c,d,e,f,g,h}
```

日付の明示も可能。

```console
$ atcli new abc300 --date 2026-09-08
```

問題ディレクトリへ移動して解答を書き、サンプルを実行する。

```console
$ cd 2026/09/08/abc300/a
$ atcli test
$ atcli test --release
$ atcli test --case sample-1
```

サンプルを問題ページから取り直すには `atcli fetch` を使う。`sample-*.in` と `sample-*.out` だけを更新し、`my-*.in` などの自作ケースは残す。

```console
$ atcli fetch
```

`tests/my-1.in` のように対応する `.out` がないケースは、実行結果を表示するだけで合否判定しない。`.out` を置くと通常の比較対象になる。

## ディレクトリ

```text
YYYY/MM/DD/contest/task/
├── main.cpp
├── meta.toml
└── tests/
    ├── sample-1.in
    └── sample-1.out
```

日付はコンテスト開催日ではなく、`atcli new` を実行して解き始めた日。設定とルートマーカは `atcli.toml`、clangd 用設定は `compile_flags.txt` に置く。

ローカルが macOS の場合、コンパイラのメジャーバージョンを合わせても AtCoder の x86_64 Linux 環境を完全には再現しない。ここでのテストは、主にコンパイルエラーとサンプル不一致を素早く見つけるためのもの。
