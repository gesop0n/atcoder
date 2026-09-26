#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N, D;
    cin >> N >> D;
    vector<int> coor(N);
    for (int i = 0; i < N; ++i) cin >> coor[i];

    vector<int> answer;
    for (int i = 0; i < N; ++i) {
        bool isAnswer = true;
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;

            if (abs(coor[i] - coor[j]) < D) {
                isAnswer = false;
                break;
            }
        }

        if (isAnswer) answer.push_back(i + 1);
    }

    cout << answer.size() << '\n';
    if (answer.size() == 0) {
    } else {
        for (int i = 0; i < (int)answer.size(); ++i) {
            cout << answer[i] << ' ';
        }
        cout << '\n';
    }
}
