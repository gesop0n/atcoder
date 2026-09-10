# atcoder

AtCoder の C++ 解答と、準備・サンプルテスト・提出を行う Rust 製 CLI `atcli` を管理するリポジトリ。

## セットアップ

Nix flakes を有効にした環境で、リポジトリのルートから次を実行する。

```console
$ git submodule update --init
$ nix develop
```

この shell には GCC 15、clangd とビルド済みの `atcli` が入っている。`atcli` 自体を変更するときは、Rust toolchain も入る開発 shell を使う。

```console
$ nix develop .#atcli
$ cargo test --manifest-path tools/atcli/Cargo.toml
```

## 使い方

コンテストの全問題について、共有する問題データと、コマンドを実行した日付の取り組みを作成する。

```console
$ atcli new abc300
# 問題データ: problems/abc300/{a,b,c,d,e,f,g,ex}
# 取り組み:   attempts/2026/09/09/abc300/{a,b,c,d,e,f,g,ex}
```

日付の明示もできる。

```console
$ atcli new abc300 --date 2026-09-08
```

問題を指定した場合は、その問題だけを作成する。ラベルは大文字小文字を区別せず、複数指定できる。

```console
$ atcli new abc300 a c ex
# 例: 2026/09/09/abc300/{a,c,ex}
```

取り組みディレクトリへ移動して解答を書き、サンプルを実行する。

```console
$ cd attempts/2026/09/08/abc300/a
$ atcli test
$ atcli test --release
$ atcli test --case sample-1
$ atcli test --rebuild
```

同じビルド設定で `main.cpp` と依存ヘッダに変更がなければ、前回のビルド結果を再利用する。`--rebuild` を指定するとキャッシュを使わず再ビルドする。

デバッグビルドがシグナルで異常終了した場合は、macOS では LLDB、Linux では GDB が利用できれば失敗ケースを再実行し、`main.cpp` の停止位置と該当行を表示する。`--release` では提出時と同じ挙動を優先するため、この追加診断は行わない。

今日の取り組みディレクトリへ移動しやすくするには、`~/.zshrc` など起動時に読み込まれる shell 設定で、`atcli path today` と `cd` を組み合わせた関数を定義する。

```zsh
atcd() {
  local atcli_target="today"
  local atcli_dir
  case "$1" in
    root | today)
      atcli_target="$1"
      shift
      ;;
  esac
  atcli_dir="$(command atcli path "$atcli_target" "$@")" || return
  builtin cd "$atcli_dir"
}
```

```console
$ atcd
$ atcd --date 2026-09-08
$ atcd root
```

サンプルを問題ページから取り直すには `atcli fetch` を使う。`sample-*.in` と `sample-*.out` だけを更新し、`my-*.in` などの自作ケースは残す。

```console
$ atcli fetch
```

`tests/my-1.in` のように対応する `.out` がないケースは、実行結果を表示するだけで合否判定しない。`.out` を置くと通常の比較対象になる。

### ログインと提出

AtCoder のログイン画面で Cloudflare のブラウザ認証が求められる場合は、ブラウザでログインしてから Developer Tools の Cookie 一覧にある `REVEL_SESSION` を取り込む。

```console
$ atcli login --session
REVEL_SESSION: # 値は画面に表示されない
```

ブラウザ認証がない環境では `atcli login` でユーザー名とパスワードによるログインも試せる。CI では `ATCODER_USERNAME` / `ATCODER_PASSWORD`、Cookie を直接取り込む場合は `ATCODER_REVEL_SESSION` を利用できる。パスワードは保存せず、セッション Cookie だけを `~/.atcli/session.json` へパーミッション `0600` で保存する。

取り組みディレクトリで `submit` を実行すると、`--release` 相当で全ローカルテストを行い、提出内容を確認してから送信する。提出後はデフォルトで判定完了まで監視する。

```console
$ atcli submit
$ atcli submit --language 'C++23 (GCC' --yes
$ atcli submit --list-languages
$ atcli submit --no-watch
```

AtCoder の提出ページで CAPTCHA が要求される練習提出は、非公式 CLI から直接送信できない。`atcli submit` が表示する URL をブラウザで開き、表示された `main.cpp` を貼り付けて CAPTCHA を完了して提出する。開催中コンテストなど、提出ページに CAPTCHA がない場合は従来どおり CLI から直接提出する。

テストに失敗した解答は提出しない。interactive 問題など、ローカル判定できない場合に限り、確認のうえ `--no-test` で明示的に省略できる。保存したセッションを削除するには `atcli logout` を使う。

提出のデフォルト値は `atcli.toml` の `[submit]` で設定する。

```toml
[submit]
language = "C++23 (GCC"
watch = true
poll_interval_ms = 2000
```

## ディレクトリ

問題ごとに共有するメタデータとテストは `problems/` に置く。

```text
problems/contest/task/
├── meta.toml
└── tests/
    ├── sample-1.in
    └── sample-1.out
```

日付ごとの取り組みは `attempts/` に置く。`attempt.toml` の `problem` は、設定した `problems_dir` から問題データへの相対パスになる。

```text
attempts/YYYY/MM/DD/contest/task/
├── attempt.toml  # problem = "abc300/a"
└── main.cpp
```

同じ問題へ別の日に取り組む場合、`problems/` のメタデータとテストは再利用し、日付ごとに異なる `main.cpp` と `attempt.toml` を作成する。日付はコンテスト開催日ではなく、`atcli new` を実行して解き始めた日付になる。設定とルートマーカは `atcli.toml`、clangd 用設定は `compile_flags.txt` に置く。

ローカルが macOS の場合、コンパイラのメジャーバージョンを合わせても AtCoder の x86_64 Linux 環境を完全には再現していない。
