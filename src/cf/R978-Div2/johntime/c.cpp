#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf =0x3f3f3f3f;
void work(){
    int n;
    cin>>n;
    string s[2];
    cin>>s[0]>>s[1];
    auto check = [&](char x,char y,char z)->bool{
        int res=(x=='A')+(y=='A')+(z=='A');
        return res>=2;
    };
    vector<vector<int>> dp(3,vector<int>(n+1,-inf));
    dp[2][0]=0;
    for(int i=0;i<n;i++){
        if(i%3==0){
            dp[2][i+3]=max(dp[2][i+3],dp[2][i]+check(s[0][i],s[0][i+1],s[0][i+2])+check(s[1][i],s[1][i+1],s[1][i+2]));
            dp[2][i+1]=max(dp[2][i+1],dp[2][i]+check(s[0][i],s[1][i],s[0][i+1]));
            dp[1][i+1]=max(dp[1][i+1],dp[2][i]+check(s[0][i],s[1][i],s[1][i+1]));
        }else if(i%3==1){
            if(i<n-3){
                dp[2][i+3]=max(dp[2][i+3],dp[2][i]+check(s[0][i+1],s[0][i+2],s[0][i+3])+check(s[1][i],s[1][i+1],s[1][i+2]));
                dp[1][i+3]=max(dp[1][i+3],dp[1][i]+check(s[0][i],s[0][i+1],s[0][i+2])+check(s[1][i+1],s[1][i+2],s[1][i+3]));
            }
            dp[2][i+2]=max(dp[2][i+2],dp[2][i]+check(s[1][i],s[1][i+1],s[0][i+1]));
            dp[2][i+2]=max(dp[2][i+2],dp[1][i]+check(s[0][i],s[0][i+1],s[1][i+1]));
        }
    }
    // for(int i=0;i<3;i++){
    //     for(int j=0;j<=n;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<dp[2][n]<<endl;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        work();
    }
    
}