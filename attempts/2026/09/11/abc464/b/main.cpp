#include <bits/stdc++.h>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> C(H);
    for (int i = 0; i < H; ++i) cin >> C[i];

    // 一番上にある "#" の行番号
    int up = H;
    // 一番下にある "#" の行番号
    int down = -1;
    // 一番左にある "#" の行番号
    int left = W;
    // 一番右にある "#" の行番号
    int right = -1;

    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j) {
            if (C[i][j] == '#') {
                up = min(up, i);
                down = max(down, i);
                left = min(left, j);
                right = max(right, j);
            }
        }

    for (int i = up; i <= down; ++i) {
        for (int j = left; j <= right; ++j) {
            cout << C[i][j];
        }
        cout << '\n';
    }

    cout << '\n';

    return 0;
};
