#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;

    vector<string> S(N);
    for (int i = 0; i < N; ++i) cin >> S[i];

    vector<int> score(N);

    for (int j = 0; j < M; ++j) {
        int vote = 0;
        for (int i = 0; i < N; ++i) {
            if (S[i][j] == '0')
                --vote;
            else
                ++vote;
        }

        if (abs(vote) == N) {
            // 全員同じ
            for (int i = 0; i < N; ++i) {
                ++score[i];
            }
        } else if (vote > 0) {
            for (int i = 0; i < N; ++i) {
                if (S[i][j] == '0') ++score[i];
            }
        } else {
            for (int i = 0; i < N; ++i) {
                if (S[i][j] == '1') ++score[i];
            }
        }
    }

    int max_score = 0;
    for (int i = 0; i < N; ++i) {
        if (max_score < score[i]) {
            max_score = score[i];
        }
    }

    for (int i = 0; i < N; ++i) {
        if (score[i] == max_score) cout << i + 1 << ' ';
    }

    cout << '\n';
}
