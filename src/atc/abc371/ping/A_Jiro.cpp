#include <bits/stdc++.h>
using namespace std;

int main()
{
    char ab,ac,bc;
    scanf("%c %c %c",&ab,&ac,&bc);
    if ((ab=='<' && ac=='>') || (ab=='>' && ac=='<'))
        printf("A");
    else if ((ab=='<' && bc=='<') || (ab=='>' && bc=='>'))
        printf("B");
    else if ((ac=='<' && bc=='>') || (ac=='>' && bc=='<'))
        printf("C");
    return 0;
}