#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    // 上位3つを常に引き継いで新しい要素と比較すればよい
    vector<int> top(3);
    cin >> top[0] >> top[1] >> top[2];
    sort(top.rbegin(), top.rend());

    cout << top[2] << '\n';

    for (int i = 3; i < N; ++i) {
        int x;
        cin >> x;

        top.push_back(x);
        sort(top.rbegin(), top.rend());
        top.pop_back();

        cout << top[2] << '\n';
    }
}
