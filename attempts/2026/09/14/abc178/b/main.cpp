#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ll A, B, C, D;
    cin >> A >> B >> C >> D;

    cout << max(max(A * C, A * D), max(B * C, B * D)) << '\n';
}
