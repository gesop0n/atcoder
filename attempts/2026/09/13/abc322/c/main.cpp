#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M);
    for (int i = 0; i < M; ++i) cin >> A[i];

    int index = 0;
    for (int i = 1; i <= N; ++i) {
        if (i > A[index]) ++index;

        cout << A[index] - i << '\n';
    }
}
