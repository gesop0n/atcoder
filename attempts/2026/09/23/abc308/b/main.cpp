#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N, M, P0;
    cin >> N >> M;
    vector<string> C(N), D(M);
    for (int i = 0; i < N; ++i) cin >> C[i];
    for (int i = 0; i < M; ++i) cin >> D[i];
    cin >> P0;
    map<string, int> menu;
    for (int i = 0; i < M; ++i) {
        cin >> menu[D[i]];
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        auto it = menu.find(C[i]);
        // iterator が end と同じ = 要素が見つからなかったということ
        if (it == menu.end())
            ans += P0;
        else
            ans += it->second;
    }

    cout << ans << '\n';
}
