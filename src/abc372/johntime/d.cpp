#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<int> ans(n+1);
    stack<int> s;
    for(int i=n;i>=1;i--){
        ans[i]=s.size();
        while(!s.empty()&&s.top()<=a[i]){
            s.pop();
        }
        s.push(a[i]);
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<' ';
    }
}