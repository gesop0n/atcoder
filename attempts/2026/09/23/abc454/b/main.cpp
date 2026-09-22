#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    set<int> seen;
    for (int i = 0; i < N; ++i) {
        int F;
        cin >> F;
        seen.insert(F);
    }

    cout << ((int)seen.size() == N ? "Yes" : "No") << '\n';
    cout << ((int)seen.size() == M ? "Yes" : "No") << '\n';

    return 0;
}
