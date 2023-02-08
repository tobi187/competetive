#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int tt, n, c;
    cin >> tt;

    for (int t = 0; t < tt; t++) {
        cin >> n >> c;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            int b;
            cin >> b;
            v[i] = i + 1 + b;
        }

        sort(v.begin(), v.end());

        int cc = 0;
        for (int a : v) {
            if (c - a >= 0) {
                cc++;
                c -= a;
            } else {
                break;
            }
        }

        cout << cc << endl;
    }
}
