#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;

    cin >> N;

    for (int i = 0; i < N; i++) {
        if (i + 1 % 3 == 0) {
            cout << "Fizz" << "\n";
        } else {
            cout << i + 1 << "\n";
        }
    }
    return 0;
}
