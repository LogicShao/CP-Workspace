#include<bits/stdc++.h>
using namespace std;
void work(){
    int n;
    cin>>n;
    bool flag=1;
    string s;
    while(flag){
        char c='0';
        for(c='0';c<='1';c++){
            if(s.size()==n){
                flag=0;
                break;
            }
            cout<<"? "<<s+c<<'\n';
            cout.flush();
            int x;
            cin>>x;
            if(x==1){
                s+=c;
                break;
            }
            if(x==0&&c=='1'){
                flag=0;
                break;
            }
        }
    }
    while(s.size()<n){
        char c='0';
        cout<<"? "<<c+s<<'\n';
        cout.flush();
        int x;
        cin>>x;
        if(x==1){
            s=c+s;
        }else{
            s='1'+s;
        }
    }
    cout<<"! "<<s<<'\n';
    cout.flush();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        work();
    }
}