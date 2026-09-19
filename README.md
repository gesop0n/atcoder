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

コンテストの全問題について、共有する問題データと、コマンドを実行した日付の取り組みを作成する。開催中のコンテストは未ログインだと問題一覧が 404 になるため、事前に `atcli login` しておく。`new` と `fetch` は保存済みセッションがあればそれを使う。

```console
$ atcli new abc300
# 問題データ: problems/abc300/{a,b,c,d,e,f,g,ex}
# 取り組み:   attempts/2026/09/09/abc300/{a,b,c,d,e,f,g,ex}
```

日付の明示もできる。

```console
$ atcli new abc300 --date 2026-09-08
```

問題を指定した場合は、その問題だけを作成する。ラベルは大文字小文字を区別せず、複数指定できる。`..` で範囲も指定できる。範囲はラベルの文字列計算ではなくコンテストの問題順で解決するため、ラベルの付け方に依存しない。

```console
$ atcli new abc300 a c ex
# 例: 2026/09/09/abc300/{a,c,ex}
$ atcli new abc300 c..e
# 例: 2026/09/09/abc300/{c,d,e}
```

`tessoku-book`（競技プログラミングの鉄則 演習問題集）のような常設コンテストも同じように扱えるが、151 問あるため問題指定を省略すると 1 日分の取り組みとして全問を作ってしまう。問題数が 20 問を超えるコンテストでは問題の指定を必須とし、本当に全問作成する場合だけ `--all` を指定する。

```console
$ atcli new tessoku-book           # エラー。問題の指定を促す
$ atcli new tessoku-book a01..a05  # problems/tessoku-book/{a01,a02,a03,a04,a05}
$ atcli new tessoku-book --all     # 151 問すべて。時間がかかる
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

テストを通過した取り組みを Git に保存するには、取り組みディレクトリで `atcli commit` を実行する。取り組みと、それが参照する問題データにある変更だけをステージしてコミットするため、別の問題ですでにステージしている変更は含まれない。コミットメッセージは問題メタデータから `Solve ABC178 B: Product Max` の形式で生成される。

```console
$ atcli commit
$ atcli commit -m "解説AC ABC178 B"
$ atcli commit --dry-run
```

`--dry-run` は、コミットやステージを行わずにメッセージと対象の変更を表示する。`atcli commit path/to/attempt` のように取り組みディレクトリを指定することもできる。テストは自動実行しないため、必要に応じて先に `atcli test` を実行する。

サンプルを問題ページから取り直すには `atcli fetch` を使う。`sample-*.in` と `sample-*.out` だけを更新し、`my-*.in` などの自作ケースは残す。

```console
$ atcli fetch
```

`tests/my-1.in` のように対応する `.out` がないケースは、実行結果を表示するだけで合否判定しない。`.out` を置くと通常の比較対象になる。

### ディレクトリ移動

atcli 自身は親 shell の cwd を変えられないため、移動系のコマンドは shell 関数のラッパーを通す。その関数は `atcli init zsh` が出力する。

```zsh
eval "$(atcli init zsh)"
```

これで `atcd`、`atcli cd`、`atcli new --cd` が使えるようになる。

```console
$ atcd                        # 今日の取り組みディレクトリ
$ atcd root                   # リポジトリのルート
$ atcd --date 2026-09-08      # 指定日の取り組みディレクトリ
$ atcli cd abc462             # attempts/YYYY/MM/DD/abc462
$ atcli cd abc462 b           # attempts/YYYY/MM/DD/abc462/b
$ atcli new abc462 b --cd     # 作成して、そのままコンテストディレクトリへ移動する
```

`atcli cd` は日付を省略するとまず今日を見て、無ければそのコンテストを含む最新の日へ遡る。数日前に解いた問題へ戻るときに日付を思い出さなくて済む。`--date` を明示した場合は遡らない。複数の問題を作った `atcli new --cd` は、コンテストディレクトリへ移動する。

`atcli` を direnv 経由でリポジトリ内でのみ PATH に載せている場合、shell 起動時に上の `eval` は実行できない。初回呼び出しで本物へ差し替えるブートストラップを置く。

```zsh
_atcli_bootstrap() {
  local _atcli_init
  _atcli_init="$(command atcli init zsh)" || return
  unfunction atcli atcd _atcli_bootstrap 2>/dev/null
  eval "$_atcli_init"
}
atcli() { _atcli_bootstrap || return; atcli "$@"; }
atcd()  { _atcli_bootstrap || return; atcd  "$@"; }
```

`atcli init zsh` の出力を取得してから `unfunction` する順序が重要で、atcli が PATH にないときもブートストラップが残り、次回また試せる。

shell 統合なしでパスだけが欲しい場合は `atcli path` を使う。`atcli path root`、`atcli path today [--date]`、`atcli path attempt <contest> [problem] [--date]` がある。

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

AtCoder の提出ページで CAPTCHA が要求される練習提出は、非公式 CLI から直接送信できない。`tessoku-book` などの常設コンテストへの提出がこれにあたる。`atcli submit` が表示する URL をブラウザで開き、表示された `main.cpp` を貼り付けて CAPTCHA を完了して提出する。開催中コンテストなど、提出ページに CAPTCHA がない場合は従来どおり CLI から直接提出する。

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
