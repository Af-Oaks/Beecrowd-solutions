#include <bits/stdc++.h>

using namespace std;
#define int long long int

int32_t main(){

    int seq_fibo[21] ={1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765,10946,17711};
    int quant,atual;
    cin>>quant;

    while(quant--){
        cin>>atual;
        int resp[21];
        for(int x=20;x>=0;x--){
            if(atual/seq_fibo[x]>0){
                resp[x]=1;
                atual = atual%seq_fibo[x];
            }
            else
                resp[x]=0;
        }
        for(int x=0;x<20;x++){
            resp[x] = resp[x+1];
        }
        int valor =0;
        for(int x=0;x<20;x++){
            valor+= seq_fibo[x]*resp[x];
        }
        cout<<valor<<"\n";
    }


    return 0;
}