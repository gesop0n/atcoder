#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n) {
    // NOTE:  ある整数n に対して √n までチェックすれば良い
    //  約数は √n を境にペアになる.
    //
    // ref:
    // - https://qiita.com/reendapo/items/4416144c7763048d761b
    // - https://qiita.com/drken/items/a14e9af0ca2d857dad23
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }

    return true;
}

int main() {
    int Q;
    cin >> Q;

    for (int i = 0; i < Q; ++i) {
        int x;
        cin >> x;
        if (isPrime(x))
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}
