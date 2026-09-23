#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    map<int, int> stock;
    for (int i = 0; i < N; ++i) {
        int A;
        cin >> A;
        stock[A]++;
    }

    for (int i = 0; i < M; ++i) {
        int B;
        cin >> B;
        auto it = stock.find(B);
        if (it == stock.end() || it->second <= 0) {
            cout << "No\n";
            return 0;
        }

        --it->second;
    }

    cout << "Yes\n";

    return 0;
}
