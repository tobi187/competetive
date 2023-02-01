#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUGDE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int tt, n;
    cin >> tt;
    for (int t = 0; t < tt; t++) {
        cin >> n;
        vector<int> peeps(n);
        for (int &a : peeps)
            cin >> a;

        sort(peeps.begin(), peeps.end());
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (peeps[i] > i)
                continue;
            for (int j = i + 1; j < n; j++) {
                if (peeps[j] > j - i) {
                    if (j + i > i)
                        count++;
                    break;
                }
            }
        }

        cout << count << endl;
    }
}
