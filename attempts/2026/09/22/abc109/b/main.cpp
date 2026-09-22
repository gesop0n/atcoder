#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    set<string> seen;
    string W;
    cin >> W;
    seen.insert(W);
    char last = W.back();

    for (int i = 1; i < N; ++i) {
        cin >> W;

        if (!seen.contains(W) && last == W.front()) {
            seen.insert(W);
            last = W.back();
        } else {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
}
