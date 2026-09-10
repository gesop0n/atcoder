#include <bits/stdc++.h>
#include <climits>
#include <cstdlib>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> L(N);
    int sum = 0;
    for (int& x : L) {
        cin >> x;
        sum += x;
    }

    int ans = INT_MAX;
    int cache = 0;
    for (int i = 0; i < L.size() - 1; ++i) {
        int tmp = abs(sum - 2 * (cache + L[i]));
        if (tmp < ans) ans = tmp;
        cache += L[i];
    }

    cout << ans << '\n';
}
