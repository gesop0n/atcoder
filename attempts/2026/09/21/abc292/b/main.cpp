#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N, Q;
    cin >> N >> Q;
    map<int, int> event;
    for (int i = 0; i < Q; ++i) {
        int E, X;
        cin >> E >> X;

        if (E == 1)
            event[X]++;
        else if (E == 2)
            event[X] += 2;
        else if (E == 3) {
            if (event[X] >= 2)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }

    return 0;
}
