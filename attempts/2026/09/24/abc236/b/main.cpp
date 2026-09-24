#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> cards(N);
    for (int i = 0; i < (4 * N) - 1; ++i) {
        int A;
        cin >> A;
        ++cards[A - 1];
    }

    for (int i = 0; i < N; ++i) {
        if (cards[i] != 4) {
            cout << i + 1 << '\n';
            return 0;
        }
    }
}
