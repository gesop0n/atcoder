#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    set<int> A;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        A.insert(a);
    }

    cout << A.size() << '\n';
}
