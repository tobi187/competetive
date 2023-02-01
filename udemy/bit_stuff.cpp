#include <bits/stdc++.h>

using namespace std;

bool isPowerOfFour(int n)
{
    auto mask = (0 << n);
    cout << bitset<8>(mask) << endl;
    cout << bitset<8>(n - 1) << endl;
    return (mask & n) == 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    cout << isPowerOfFour(n);
}