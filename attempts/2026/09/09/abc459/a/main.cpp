#include <bits/stdc++.h>

using namespace std;

int main() {
    string ans = "HelloWorld";
    int x;
    cin >> x;

    cout << ans.replace(x - 1, 1, "");
}
