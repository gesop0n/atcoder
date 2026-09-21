#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    set<int> se;
    for (int i = 0; i < N; ++i) {
        int D;
        cin >> D;
        se.insert(D);
    }
    cout << se.size() << '\n';
}
