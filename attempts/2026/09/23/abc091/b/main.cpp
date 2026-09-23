#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    map<string, int> words;
    int N, M;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string S;
        cin >> S;
        ++words[S];
    }
    cin >> M;
    for (int i = 0; i < M; ++i) {
        string T;
        cin >> T;
        --words[T];
    }

    int ans = 0;
    for (auto [key, value] : words) {
        if (ans < value) {
            ans = value;
        }
    }

    cout << ans << '\n';
}
