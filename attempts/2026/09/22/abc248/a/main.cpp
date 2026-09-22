#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;
    bool appeared[10] = {};
    for (char c : S) {
        appeared[c - '0'] = true;
    }

    for (int i = 0; i <= 9; ++i) {
        if (!appeared[i]) {
            cout << i << '\n';
            return 0;
        }
    }

    return 0;
}
