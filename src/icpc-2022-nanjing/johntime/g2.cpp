#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll __gcd(ll a, ll b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}
void work()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &ai : a)
        cin >> ai;
    ll sumc = 0, sum = 0;
    ll p=1,q=1;
    for(auto &ai:a){
        if(ai==1){
            q++;
            p++;
        }
        if(ai==-1){
            if(p==1){
                sumc--;
                q++;
                p+=2;
                if(sumc<0){
                    cout<<"-1\n";
                    return;
                }
                p--;
            }
            else{
                p--;
            }
        }
        if(ai==0){
            if(p==1){
                q++,p++;
            }else{
                p--;
                sumc++;
            }
        }
    }
    ll b = __gcd(p, q);
    cout << q / b << ' ' << p / b << '\n';
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        work();
    }
}