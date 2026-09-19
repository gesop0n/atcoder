#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N;
    string S, T;
    cin >> N;
    cin >> S;
    cin >> T;

    for (int i = 0; i < N; ++i) {
        if (T[i] == '*')
            continue;
        else {
            if (S[i] == T[i])
                continue;
            else {
                cout << "No\n";
                return 0;
            }
        }
    }

    cout << "Yes\n";
}
