#include <bits/stdc++.h>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int N;
    cin >> N;
    map<int, int> C;
    int color;
    for (int i = 0; i < N; ++i) {
        cin >> color;
        ++C[color];
    }

    auto it = max_element(C.begin(), C.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });

    cout << N - it->second << '\n';
}
