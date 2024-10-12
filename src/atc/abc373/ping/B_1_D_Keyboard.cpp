#include <bits/stdc++.h>
using namespace std;

int main()
{
    char in;
    map<int, int> key;
    for (int i = 0; i < 26; ++i)
    {
        in = getchar();
        key[in] = i;
    }
    int ans = 0;
    for (int i = 'A'; i < 'Z'; ++i)
        ans += abs(key[i] - key[i + 1]);
    cout << ans;
    return 0;
}