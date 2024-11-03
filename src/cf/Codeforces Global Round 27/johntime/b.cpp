#include<bits/stdc++.h>
using namespace std;
void work(){
    int n;
    cin>>n;
    string s;
    if(n==1||n==3){
        cout<<-1<<endl;
        return;
    }
    for(int i=1;i<=n;i++){
        s.push_back('3');
    }
    if(n&1)s[n-4]='6';
    s[n-1]='6';
    s[n-2]='6';
    cout<<s<<endl;
}
int main(){
    int t;
    cin >> t;
    while(t--)work();
}