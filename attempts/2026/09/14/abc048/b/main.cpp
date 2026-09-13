#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll a, b, x;
    cin >> a >> b >> x;

    // (1 以上 b 以下の x の倍数の個数) + 1
    ll upper = b / x;

    if (a == 0) {
        // 0 も x で割り切れるので 1 を足す
        cout << upper + 1 << '\n';
    } else {
        // (a-1) 未満の x で割り切れる個数を求めて引く
        ll lower = (a - 1) / x;
        cout << upper - lower << '\n';
    }
}
