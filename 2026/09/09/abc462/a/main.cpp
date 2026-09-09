#include <bits/stdc++.h>
#include <cctype>

using namespace std;

int main() {
    string s;
    cin >> s;
    string ans = "";
    for (char c : s) {
        if (isdigit(c)) ans += c;
    }

    cout << ans << '\n';
}
