#include<bits/stdc++.h>
using namespace std;
int main(){
    char ch[3];
    cin>>ch[0]>>ch[1]>>ch[2];
    if(ch[0]=='>'){//A>B
        if(ch[1]=='>'){//A>C
            if(ch[2]=='>'){//B>C
                cout<<"B";
            }else{
                cout<<"C";
            }
        }else{//A<C
            if(ch[2]=='<'){
                cout<<"A";
            }
        }
    }else{//A<B
        if(ch[1]=='<'){//A<C
            if(ch[2]=='>'){//B>C
                cout<<'C';
            }else{//B<C
                cout<<'B';
            }
        }else{//A>C
            if(ch[2]=='>'){
                cout<<'A';
            }
        }
    }
}