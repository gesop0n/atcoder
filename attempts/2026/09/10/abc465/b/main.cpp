#include <bits/stdc++.h>

using namespace std;

int main() {
    int X, Y, L, R, A, B;
    cin >> X >> Y >> L >> R >> A >> B;

    int ans = 0;
    for (int i = 1; i <= 24; ++i) {
        if (i >= A && i < B) {
            if (i >= L && i < R) {
                ans += X;
            } else {
                ans += Y;
            }
        }
    }

    cout << ans << '\n';
}
