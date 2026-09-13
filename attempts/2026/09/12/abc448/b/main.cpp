#include <bits/stdc++.h>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> C(M);
    vector<int> S(M, 0);
    for (int i = 0; i < M; ++i) {
        cin >> C[i];
    }

    for (int i = 0; i < N; ++i) {
        int A, B;
        cin >> A >> B;
        S[A - 1] += B;
    }

    int ans = 0;
    for (int i = 0; i < M; ++i) {
        ans += min(C[i], S[i]);
    }

    cout << ans << '\n';

    return 0;
}
