#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<vector<int>> g(n+1, vector<int>(n+1));
    for(int i=0; i<m; i++) {
        int a, b;
        cin>>a>>b;
        g[a][b] = 1;
        g[b][a] = 1;
    }
    cin>>m;
    vector<vector<int>> h(n+1, vector<int>(n+1));
    for(int i=0; i<m; i++) {
        int a, b;
        cin>>a>>b;
        h[a][b] = 1;
        h[b][a] = 1;
    }
    vector<vector<int>> a(n+1, vector<int>(n+1));
    for(int i=1; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            cin>>a[i][j];
            a[j][i] = a[i][j];
        }
    }
    long long ans=0x7fffffffffffffff;
    int p[n+1];
    for(int i=1;i<=n;i++) p[i]=i;
    do {
        long long res=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(g[i][j]+h[p[i]][p[j]]==1){
                    res+=a[p[i]][p[j]];
                }
            }
        }
        ans=min(ans,res);
    }while(next_permutation(p+1,p+n+1));
    cout<<ans<<endl;
}
