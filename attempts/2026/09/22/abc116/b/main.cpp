#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int f(int n) {
    if (n % 2 == 0)
        return n / 2;
    else
        return 3 * n + 1;
}

int main() {
    int s;
    cin >> s;

    set<int> st;
    st.insert(s);
    int a = f(s);
    int ans = 2;
    while (!st.contains(a)) {
        st.insert(a);

        a = f(a);
        ++ans;
    }
    cout << ans << '\n';
}
