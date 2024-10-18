// 找规律用，输出 s 到 e 的二进制以及奇数位 1 的个数

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int s,e;
    cin >> s >> e;
    vector<int> cnt(300, 0);
    for (int i = s; i <= e; ++i)
    {
        cout << i << "\t";
        int temp = 1, c = 0;
        for (; temp <= i; temp *= 2, ++c);
        temp /= 2;
        for (int c = 1; temp; temp /= 2, ++c)
        {
            cout << (((i & temp) > 0) ? 1:0);
            if (c % 2 != 0)
                cnt[c / 2]+=((i & temp) > 0) ? 1:0;
        }
        cout << '\n';
    }
    int tot = 0;
    for (auto i : cnt)
    {
        if (i <= 0)
            break;
        tot += i;
        cout << " +" << i;
    }
    cout << " = " << tot << '\n';
    return 0;
}