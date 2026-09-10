#include <bits/stdc++.h>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a, b;
    string s;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> s;
        if (s == "keep") ans += b - a;
    }

    cout << ans << '\n';
}
