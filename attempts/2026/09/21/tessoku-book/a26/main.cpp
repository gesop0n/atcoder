#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool isPrime(int x) {
    if (x == 0 || x == 1) return false;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) return false;
    }

    return true;
}

int main() {
    int Q;
    cin >> Q;

    for (int i = 0; i < Q; ++i) {
        int X;
        cin >> X;
        if (isPrime(X)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
