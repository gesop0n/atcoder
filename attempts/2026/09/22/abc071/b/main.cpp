#include <bits/stdc++.h>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;
    vector<int> baket(26);
    for (char c : S) {
        baket[c - 'a']++;
    }

    for (int i = 0; i < baket.size(); ++i) {
        if (baket[i] == 0) {
            cout << (char)(i + 97) << '\n';
            return 0;
        }
    }

    cout << "None\n";
}
