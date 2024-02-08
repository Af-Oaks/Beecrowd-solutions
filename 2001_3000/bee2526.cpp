#include <bits/stdc++.h>

using namespace std;
#define int long long int

int32_t main(){

    int dia,valor,variacao,tempo;
    cin>>dia>>valor>>variacao>>tempo;

    if(dia%2==0){
        if((dia+tempo)%2 ==0){
            cout<<valor<<"\n";
        }
        else{
            cout<<valor-variacao<<"\n";
        }
    }
    if(dia%2==1){
        if((dia+tempo)%2 ==0){
            cout<<valor+variacao<<"\n";
        }
        else{
            cout<<valor<<"\n";
        }
    }


    return 0;
}