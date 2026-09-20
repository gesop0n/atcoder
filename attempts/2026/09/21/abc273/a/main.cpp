#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int f(int x) {
    if (x == 0) return 1;

    return x * f(x - 1);
}

int main() {
    int N;
    cin >> N;

    cout << f(N) << '\n';
}
