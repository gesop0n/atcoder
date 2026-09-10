#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    char X;
    cin >> N >> X;
    string S;

    for (int i = 0; i < N; ++i) {
        cin >> S;

        int index = (X - '0') - 17;
        if (S[index] == 'o') {
            cout << "Yes\n";
            return 0;
        }
    }

    cout << "No\n";
}
