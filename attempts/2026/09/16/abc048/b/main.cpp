#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll A, B, X;
    cin >> A >> B >> X;

    // 1 以上 B 以下の X で割り切れる個数
    ll upper = B / X;

    if (A == 0) {
        // 0 も X で割り切れるので 1を足す
        cout << upper + 1 << '\n';
    } else {
        // (A-1) 未満の X で割り切れる個数を求めて引く
        ll lower = (A - 1) / X;
        cout << upper - lower << '\n';
    }
}
