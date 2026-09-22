#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
using ll = long long;

int main() {
    string W;
    cin >> W;
    unordered_map<char, int> map_words;
    for (char c : W) {
        map_words[c]++;
    }

    bool result = true;
    for (auto it = map_words.begin(); it != map_words.end(); ++it) {
        if (it->second % 2 == !0) {
            result = false;
            break;
        }
    }

    if (result)
        cout << "Yes\n";
    else
        cout << "No\n";
}
