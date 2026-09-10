#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;

    int ctmp;
    for (int i = 0; i < N; i++) {
        cin >> ctmp;
        if (A + B == ctmp) {
            cout << i + 1 << "\n";
            return 0;
        }
    }

    return -1;
}
