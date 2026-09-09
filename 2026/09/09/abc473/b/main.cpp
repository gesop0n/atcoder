#include <bits/stdc++.h>
#include <iterator>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int& x : A) cin >> x;

    int ans = 0;
    while (!A.empty()) {
        // 配列の最後尾を取得し、削除
        int a = A.back();
        A.pop_back();

        // 同じカードが見つかったかどうか
        bool found = false;
        for (int i = 0; i < A.size(); i++) {
            // 同じカードが見つかったら
            if (A[i] == a) {
                found = true;
                // そのカードを削除
                A.erase(begin(A) + i);
                break;
            }
        }

        if (!found) {
            ans += a;
        }
    }

    cout << ans << '\n';
}
