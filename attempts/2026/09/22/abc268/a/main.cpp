#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    set<int> st;
    int x;
    for (int i = 0; i < 5; ++i) {
        cin >> x;
        st.insert(x);
    }

    cout << st.size() << '\n';
}
