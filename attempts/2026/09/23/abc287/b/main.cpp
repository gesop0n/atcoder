#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    set<string> T;
    for (int i = 0; i < N; ++i) cin >> S[i];
    for (int j = 0; j < M; ++j) {
        string t;
        cin >> t;
        T.insert(t);
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        string last3 = S[i].substr(S[i].size() - 3);
        if (T.contains(last3)) ++ans;
    }

    cout << ans << '\n';
}
