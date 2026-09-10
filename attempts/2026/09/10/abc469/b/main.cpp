#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    string S;
    cin >> N;
    cin >> S;

    int ans = 0;
    for (int i = 0; i < S.size(); ++i) {
        if (S[i] != 'x') continue;

        if (i - 1 >= 0 && S[i - 1] != 'x') continue;

        if (i + 1 <= S.length() - 1 && S[i + 1] != 'x') continue;

        ++ans;
    }

    cout << ans << '\n';
}
