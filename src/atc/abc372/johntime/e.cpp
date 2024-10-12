#include<bits/stdc++.h>
using namespace std;
constexpr int N = 2e5+10;
int f[N];
vector<set<int>> a(N);
int find(int x){
    return f[x]==x?x:f[x]=find(f[x]);
}
int main(){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        f[i]=i;
    }
    for(int i=1;i<=n;i++){
        a[i].insert(i);
    }
    while(q--){
        int opt;
        cin>>opt;
        if(opt==1){
            int u,v;
            cin>>u>>v;
            u=find(u),v=find(v);
            if(u!=v){
                if(a[u].size()>a[v].size()){
                    swap(u,v);
                }
                f[u]=v;
                for(auto x:a[u]){
                    a[v].insert(x);
                }
                a[u].clear();
            }
        }
        if(opt==2){
            int v,k;
            cin>>v>>k;
            v=find(v);
            if(a[v].size()<k){
                cout<<-1<<endl;
            }else{
                cout<<*prev(a[v].end(),k)<<endl;
            }
        }
    }
}