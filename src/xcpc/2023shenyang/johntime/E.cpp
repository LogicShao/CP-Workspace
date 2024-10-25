#include<bits/stdc++.h>
using namespace std;
int main(){
    int X,Y,P,Q;
    cin>>X>>Y>>P>>Q;
    auto f=vector<vector<vector<int>>>(X+1,vector<vector<int>>(Y+1,vector<int>(2,-1)));
    queue<tuple<int,int,int>> q;
    q.push({X,Y,0});
    f[X][Y][0]=0;
    while(q.size()){
        auto [x,y,k]=q.front();
        int z=X-x,t=Y-y;
        q.pop();
        if(x==0){
            cout<<f[x][y][k]<<endl;
            return 0;
        }
        if(k==0){   
            for(int i=0;i<=x;i++){
                for(int j=0;j<=y;j++){
                    int nx=x-i,ny=y-j;
                    int nz=z+i,nt=t+j;
                    if(i+j>P)continue;
                    if(nx==0 or nx+Q>=ny){
                        if(f[nx][ny][1]==-1){
                            f[nx][ny][1]=f[x][y][0]+1;
                            q.push({nx,ny,1});
                        }
                    }
                }
            }
        }else{
            for(int i=0;i<=z;i++){
                for(int j=0;j<=t;j++){
                    int nx=x+i,ny=y+j;
                    int nz=z-i,nt=t-j;
                    if(i+j>P)continue;
                    if(nz==0 or nz+Q>=nt){
                        if(f[nx][ny][0]==-1){
                            f[nx][ny][0]=f[x][y][1]+1;
                            q.push({nx,ny,0});
                        }
                    }
                }
            }
        }
    }
    int ans=INT_MAX;
    for(int i=0;i<=Y;i++){
        if(f[0][i][1]!=-1)ans=min(ans,f[0][i][1]);
    }
    if(ans>220)cout<<-1<<endl;
    else cout<<ans<<endl;
}