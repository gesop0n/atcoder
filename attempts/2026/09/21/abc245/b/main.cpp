#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N;
    set<int> aset;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int A;
        cin >> A;
        aset.insert(A);
    }

    // 0~N まで探索すれば十分である.
    for (int i = 0; i <= N; ++i) {
        if (aset.contains(i))
            continue;
        else {
            cout << i << '\n';
            return 0;
        }
    }

    return 0;
}
