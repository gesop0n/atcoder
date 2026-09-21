#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N, Q;
    cin >> N >> Q;
    map<int, int> T;
    for (int i = 0; i < Q; ++i) {
        int t;
        cin >> t;
        ++T[t];
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (T[i] % 2 == 0)
            ++ans;
        else
            continue;
    }

    cout << ans << '\n';
}
