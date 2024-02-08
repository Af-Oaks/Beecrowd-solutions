#include <bits/stdc++.h>

using namespace std;
/*
    so fazer checagem se o valor anterior é maior ou menor
*/

int main(){

    int carry;
    vector<int> cartas;
    for(int x=0;x<5;x++){
        scanf("%d",&carry);
        cartas.push_back(carry);
    }
    int cresc=1,decres=1;
    for(int x=0;x<4;x++){
        if(cartas[x]>cartas[x+1])
            cresc =0;
        else if(cartas[x]<cartas[x+1])
            decres =0;
    }

    if(cresc)
        printf("C\n");
    else if(decres)
        printf("D\n");
    else
        printf("N\n");

    return 0;
}