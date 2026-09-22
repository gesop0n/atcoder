#include <bits/stdc++.h>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;
    vector<int> appeared(26);
    for (char c : S) {
        appeared[c - 'a']++;
    }

    char ans = 'a';
    for (char c = 'b'; c <= 'z'; ++c) {
        if (appeared[c - 'a'] > appeared[ans - 'a']) ans = c;
    }

    cout << ans << '\n';
}
