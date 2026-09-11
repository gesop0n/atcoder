#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> ans(N);
    for (int i = 0; i < N; ++i) {
        int K;
        cin >> K;

        for (int j = 0; j < K; ++j) {
            int A;
            cin >> A;

            // 人A は, 人i+1 からギフトを受け取った
            ans[A - 1].push_back(i + 1);
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << ans[i].size();

        for (int person : ans[i]) cout << " " << person;

        cout << '\n';
    }

    return 0;
}
