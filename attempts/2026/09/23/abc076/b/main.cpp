#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;

    int ans = 1;
    int tmpa, tmpb;
    for (int i = 0; i < N; ++i) {
        tmpa = ans * 2;
        tmpb = ans + K;

        ans = min(tmpa, tmpb);
    }

    cout << ans << '\n';
}
