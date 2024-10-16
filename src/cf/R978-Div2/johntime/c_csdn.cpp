#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=2e9;
int n;
bool check(int a,int b,int c){
	int p=(a=='A'),q=(b=='A'),r=(c=='A');
	return (p+q+r>=2);
}
void solve(){
	cin>>n;
	string s[2];
	cin>>s[0]>>s[1];
	vector<vector<int> > dp(2,vector<int>(n+1,-inf));
	dp[0][0]=0;
	for(int i=0;i<n;i++){
		if(i%3==0){
			dp[0][i+3]=max(dp[0][i+3],
                           dp[0][i]+check(s[0][i],s[0][i+1],s[0][i+2])	//###
                           +check(s[1][i],s[1][i+1],s[1][i+2]));		//###

			dp[0][i+1]=max(dp[0][i+1],									//##
                           dp[0][i]+check(s[0][i],s[1][i],s[0][i+1]));	//#.
            
			dp[1][i+1]=max(dp[1][i+1],										//#.
                           dp[0][i]+check(s[0][i],s[1][i],s[1][i+1]));		//##

		}else if(i%3==1){
			if(i<n-3){
				dp[0][i+3]=max(dp[0][i+3],
                               dp[0][i]+check(s[0][i+1],s[0][i+2],s[0][i+3])	//.###
                               +check(s[1][i],s[1][i+1],s[1][i+2]));			//###.
                
				dp[1][i+3]=max(dp[1][i+3],
                               dp[1][i]+check(s[0][i],s[0][i+1],s[0][i+2])	//###.
                               +check(s[1][i+1],s[1][i+2],s[1][i+3]));		//.###
			}
            
			dp[0][i+2]=max(dp[0][i+2],										//.#
                           dp[0][i]+check(s[1][i],s[1][i+1],s[0][i+1]));	//##
	
			dp[0][i+2]=max(dp[0][i+2],										//##
                           dp[1][i]+check(s[0][i],s[0][i+1],s[1][i+1]));	//.#
		}
	}
	cout<<dp[0][n]<<endl;
}
signed main(){
    int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
