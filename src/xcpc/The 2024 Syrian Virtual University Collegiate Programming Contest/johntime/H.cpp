#include <bits/stdc++.h>
using namespace std;

#define LL long long
int n;

bool check(int x, vector<LL> &a)
{
    LL tot = 0;
    priority_queue<LL> q;
    for(auto v:a){
        while(v%2==0){
            v/=2;
            tot++;
        }
        q.push(v);
    }
    LL ans=0;
    while(!q.empty()){
        auto v=q.top();
        q.pop();
        if(v>x){
            ans++;
        }else{
            while(v<x&&tot){
                v*=2;
                tot--;
            }
            if(v>=x){
                ans++;
            }
        }
        if(ans>=x)return true;
    }
    return false;

}

void solve()
{
    cin >> n;
    vector<LL> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int l = 1, r = n;
    while (l < r)
    {
        int mid = (l + r + 1) / 2;
        if (check(mid, a))
            l = mid;
        else
            r = mid - 1;
    }
    cout << l << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}