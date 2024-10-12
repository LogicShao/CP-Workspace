#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, in, max1 = -1e10, max2 = -1e10;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> in;
        max1 = max(max1, in);
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> in;
        max2 = max(max2, in);
    }
    cout << (max1 + max2);
    return 0;
}