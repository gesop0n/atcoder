#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, Y;
    cin >> N >> Y;

    for (int i = N; i >= 0; --i)
        for (int j = N - i; j >= 0; --j) {
            int k = N - i - j;

            if (10000 * i + 5000 * j + 1000 * k == Y) {
                cout << i << " " << j << " " << k << '\n';
                return 0;
            }
        }

    cout << "-1 -1 -1\n";
}
