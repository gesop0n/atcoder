#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> color_max(M, -1);
    int C, S;
    for (int i = 0; i < N; ++i) {
        cin >> C >> S;
        if (color_max[C - 1] < S) color_max[C - 1] = S;
    }

    for (int i = 0; i < color_max.size(); ++i) {
        cout << color_max[i] << " ";
    }

    cout << '\n';
}
