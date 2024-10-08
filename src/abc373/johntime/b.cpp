#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int pos=s.find('A');
    int ans=0;
    for(char ch='A';ch<='Z';ch++){
        ans+=abs((int)(pos-s.find(ch)));
        pos=s.find(ch);
    }
    cout<<ans;
}