#include<bits/stdc++.h>
using namespace std;
constexpr int N=1e6+10;
int prime[N<<1],st[N<<1],cnt;
void work(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &x:a) cin>>x;
    int ans=0;
    for(auto x:a){
        int res=0;
        for(int i=0;i<cnt&&prime[i]<=x/prime[i];i++){//分解x的所有质因数
            if(x%prime[i]==0){
                while(x%prime[i]==0){//循环分解x的质数因子，保证后面x不再有这个质数因子
                    x/=prime[i];
                    ++res;
                }
            }
        }
        if(x>1) ++res;//从2到根号x都没有整除x的数，那么x就是一个质数
        if(res>=3) ++ans;//如果res大于等于3，那么两者一个是质数，一个是合数，是争夺的对象
    }
    cout<<n-ans/2<<endl;//后手需要下取整
}

void get_primes(int n) {
  for (int i = 2; i <= n; ++i) {
    if (!st[i])
      prime[cnt++] = i;
    for (int j = 0; prime[j] <= n / i; ++j) {
      st[prime[j] * i] = true;
      if (i % prime[j] == 0)
        break;
    }
  }
}

void debug(int n){
    for(int i=0;i<10;i++){
        cout<<prime[i]<<" ";
    }
    cout<<endl;
}
int main(){
    get_primes(N);
    int t;
    cin>>t;
    while(t--){
        work();
    }
}