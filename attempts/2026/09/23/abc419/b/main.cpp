#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int Q;
    cin >> Q;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < Q; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            pq.push(x);
        } else {
            cout << pq.top() << '\n';
            pq.pop();
        }
    }
}
