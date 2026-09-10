#include <bits/stdc++.h>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    int N;
    cin >> N;
    map<string, int> s;
    string tmps;
    for (int i = 0; i < N; ++i) {
        cin >> tmps;
        for (char& c : tmps) c = tolower(c);
        ++s[tmps];
    }

    auto max_it = max_element(
        s.begin(), s.end(),
        [](const auto& a, const auto& b) { return a.second < b.second; });

    cout << max_it->second << '\n';
}
