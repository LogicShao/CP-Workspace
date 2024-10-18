#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n=s.size();
    for(int i=0;i<n-11;i++){
        string t=s.substr(i,12);
        if(t=="KaaaKaaaKaaa"){
            cout<<"Woken Up"<<endl;
            return 0;
        }
    }
    cout<<"Still Asleep"<<endl;
}