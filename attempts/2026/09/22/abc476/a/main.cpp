#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;

    char last = S.back();
    cout << (last == 'e' ? S + "r" : S + "er") << '\n';
}
