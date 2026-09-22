#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;
    set<string> st;
    for (int i = 0; i < S.size(); ++i) {
        for (int j = i + 1; j <= S.size(); ++j) {
            st.insert(S.substr(i, j - i));
        }
    }

    cout << st.size() << '\n';
}
