#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    // NOTE: set<string> だと S = "ab", T = "c" と S = "a". T = "bc"
    // で衝突してしまう。 pair を用いると解消できる
    // もしくは、英小文字以外の区切り文字を入れても良い。
    // その場合 unordered_set<string> もアリかも. これなら O(1)
    set<pair<string, string>> seen;
    for (int i = 0; i < N; ++i) {
        string S, T;
        cin >> S >> T;
        pair<string, string> name = {S, T};
        if (seen.contains(name)) {
            cout << "Yes\n";
            return 0;
        } else {
            seen.insert(name);
        }
    }

    cout << "No\n";
}
