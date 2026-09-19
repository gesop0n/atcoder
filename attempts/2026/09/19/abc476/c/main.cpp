#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> window(3);
    int ans = 0;
    cin >> window[0] >> window[1];

    for (int i = 2; i < N; ++i) {
        cin >> window[2];
        sort(window.rbegin(), window.rend());
        ans = max(ans, window[2]);

        cout << ans << '\n';
    }
}
