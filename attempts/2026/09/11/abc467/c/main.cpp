#include <bits/stdc++.h>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    if (W / (W * W) >= 25)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}
