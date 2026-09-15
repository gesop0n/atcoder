#include <bits/stdc++.h>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> C(M);
    for (int i = 0; i < M; ++i) cin >> C[i];

    vector<int> usage(M, 0);

    for (int i = 0; i < N; ++i) {
        int A, B;
        cin >> A >> B;

        usage[A - 1] = min(usage[A - 1] + B, C[A - 1]);
    }

    int ans = 0;
    for (int i = 0; i < M; ++i) ans += usage[i];
    cout << ans << '\n';
}
