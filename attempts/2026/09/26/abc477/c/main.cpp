#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct RollingHash {
    string S;
    vector<unsigned long long> pow_base;
    vector<unsigned long long> hash;
    RollingHash(string s, unsigned long long base = 317LL)
        : pow_base(s.length() + 1, 1), hash(s.length() + 1, 0) {
        S = s;
        for (int i = 0; i < (int)S.length(); ++i) {
            hash[i + 1] = hash[i] * base + int(S[i]);
            pow_base[i + 1] = pow_base[i] * base;
        }
    }
    unsigned long long get(int l, int r) {
        return hash[r] - hash[l] * pow_base[r - l];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    string S, T;
    cin >> S >> T;

    int n = (int)S.size();
    int m = (int)T.size();

    // ハッシュはクエリの外で一度だけ作る
    RollingHash hashS(S);
    RollingHash hashT(T);

    unsigned long long target = hashT.get(0, m);

    // prefix[k]:
    // 開始位置が [0, k) にある T の出現数
    vector<int> prefix(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i];

        if (i + m <= n && hashS.get(i, i + m) == target) {
            ++prefix[i + 1];
        }
    }

    while (Q--) {
        int L, R;
        cin >> L >> R;

        // 区間が T より短ければ含まれない
        if (R - L + 1 < m) {
            cout << "No\n";
            continue;
        }

        int count = prefix[R - m + 1] - prefix[L - 1];

        cout << (count > 0 ? "Yes" : "No") << '\n';
    }

    return 0;
}
