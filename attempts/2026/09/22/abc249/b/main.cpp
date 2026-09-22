#include <bits/stdc++.h>
#include <cctype>

using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;
    bool upper = false, lower = false;
    set<char> st;
    for (char c : S) {
        st.insert(c);

        if (isupper(c))
            upper = true;
        else
            lower = true;
    }

    cout << (upper && lower && st.size() == S.size() ? "Yes" : "No") << '\n';
}
