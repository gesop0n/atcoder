#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;

    cin >> N;
    const int half = N / 2;

    int tmp_a = 0, sum = 0;

    for (int i = 0; i < N; i++) {
        cin >> tmp_a;

        if (i >= half) {
            sum += tmp_a;
        }
    }

    cout << sum << "\n";

    return 0;
}
