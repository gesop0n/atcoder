#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (auto& x : a) cin >> x;

    int ans = 0;
    for (int i = 1; i < N - 1; i++) {
        if (a[i - 1] < a[i] && a[i] > a[i + 1]) ans++;
    }

    cout << ans << '\n';
}
