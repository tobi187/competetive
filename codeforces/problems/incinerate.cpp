#include <bits/stdc++.h>

// https://codeforces.com/problemset/problem/1763/B

using namespace std;

struct sort_pair {
    bool operator()(const pair<int, int> &l, const pair<int, int> &r) {
        return l.first < r.first;
    }
};

int main() {
#ifndef ONLINE_JUGDE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int tt, n, k, l;
    cin >> tt;

    for (int t = 0; t < tt; t++) {
        cin >> n >> k;
        vector<pair<int, int>> h(n);
        int mh = 0;
        vector<int> temp(n);
        for (auto &a : temp)
            cin >> a;
        for (int j = 0; j < n; j++) {
            cin >> l;
            h[j] = make_pair(temp[j], l);
            mh = max(mh, temp[j]);
        }
        int minIndex = 0;
        int dec = 0;
        sort(h.begin(), h.end(), sort_pair());
        while (k > 0 && mh > 0) {
            dec += k;
            mh -= dec;
            // maybe binary search here
            for (int i = minIndex; i < n; i++) {
                if (h[i].first > dec) {
                    minIndex = i;
                    break;
                }
            }
            int m = INT_MAX;
            for (int i = minIndex; i < n; i++)
                m = min(m, h[i].second);
            k -= m;
        }
        cout << (mh <= 0 ? "YES" : "NO") << endl;
    }
}
