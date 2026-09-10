#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x >= 0) {
            cout << "No" << '\n';
            return 0;
        }
    }

    cout << "Yes" << '\n';
}
