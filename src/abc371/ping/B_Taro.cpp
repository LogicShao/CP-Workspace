#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> ta(n+20,0);
    int a; char b;
    for (int i=0;i<m;++i)
    {
        cin >> a >> b;
        if (b=='M')
        {
            ta[a]++;
            if (ta[a]==1)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
        else
            cout << "No\n";
    }
    return 0;
}