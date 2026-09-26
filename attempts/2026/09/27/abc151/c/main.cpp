#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    ll ac = 0, penalty = 0;

    vector<ll> wa(N, 0), isac(N, 0);
    for (int i = 0; i < M; ++i) {
        int p;
        string S;
        cin >> p >> S;
        --p;
        if (S == "AC") {
            if (!isac[p]) {
                ++ac;
                penalty += wa[p];
                isac[p] = true;
            }
        } else
            wa[p]++;
    }

    cout << ac << " " << penalty << '\n';
}
