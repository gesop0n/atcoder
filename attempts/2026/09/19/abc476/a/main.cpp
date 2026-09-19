#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;

    string end = S.substr(S.length() - 1);
    if (end == "e")
        cout << S << "r\n";
    else
        cout << S << "er\n";
}
