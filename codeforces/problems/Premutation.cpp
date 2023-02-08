#include <bits/stdc++.h>

using namespace std;
// https://codeforces.com/problemset/problem/1790/C

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int tt, n, a;
    cin >> tt;
    for (int t = 0; t < tt; t++) {
        cin >> n;

        int v[n - 1][2];
        for (int i = 0; i < n; i++) {
            int bb = 0, c = 0;
            cin >> a;
            bb++;
            v[i][0] = a;
            for (int j = 1; j < n - 1; j++) {
                cin >> a;
                if (a == v[i][0]) {
                    bb++;
                } else {
                    v[i][1] = a;
                    c++;
                }
            }
            if (c > bb) swap(v[i][0], v[i][1]);
        }
        for (int i = 0; i < n; i++) {
            // cout << "v0: " << v[i][0] << "; v1: " << v[i][1] << endl;
        }

        cout << v[0][0] << " ";
        for (int i = 1; i < n - 2; i++) {
            if (v[i - 1][1] == v[i][0] || v[i - 1][0] == v[i][0])
                cout << v[i][0] << " ";
            else
                cout << v[i][1] << " ";
        }
        cout << v[n - 2][1] << " ";
        cout << v[n - 2][0] << endl;
    }
}
