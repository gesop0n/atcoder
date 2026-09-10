#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

int main() {
    int M, D;
    string S;
    cin >> M >> D;
    cin >> S;

    int ans = 0;
    for (int x = 0; x < S.length(); ++x) {
        // ガードマンに監視されているかどうか
        bool watched = false;

        // 文字 x が どのガーディアンからも監視されていないか愚直に調べる
        for (int i = 0; i < S.length(); ++i) {
            if (S[i] == 'G' && abs(x - i) <= D) {
                // 監視されている場合はアーリーリターン
                watched = true;
                break;
            }
        }

        if (!watched) ++ans;
    }
    cout << ans << '\n';
}
