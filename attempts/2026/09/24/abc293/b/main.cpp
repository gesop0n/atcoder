#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<bool> called(N);
    for (int i = 0; i < N; ++i) {
        int A;
        cin >> A;
        if (!called[i]) called[A - 1] = true;
    }

    vector<int> ans;
    for (int i = 0; i < N; ++i) {
        if (!called[i]) ans.push_back(i + 1);
    }

    cout << ans.size() << '\n';
    for (int i = 0; i < (int)ans.size(); ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}
