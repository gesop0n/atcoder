#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    map<string, int> votes;
    for (int i = 0; i < N; ++i) {
        string S;
        cin >> S;
        ++votes[S];
    }

    string ans;
    int max_value = -1;
    for (auto [key, value] : votes) {
        if (max_value < value) {
            ans = key;
            max_value = value;
        }
    }

    cout << ans << '\n';
}
