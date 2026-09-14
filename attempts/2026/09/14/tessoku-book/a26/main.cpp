#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool isPrime(int n) {
    if (n < 2) return false;

    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }

    return true;
}

int main() {
    int Q;
    cin >> Q;

    for (int i = 0; i < Q; ++i) {
        int X;
        cin >> X;

        if (isPrime(X))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}
