#include <bits/stdc++.h>

using namespace std;
#define int long long int

int32_t main(){

    int quant,divisao;
    cin>>quant>>divisao;

    int inteira = quant/divisao;
    int resto = quant%divisao;

    if(resto ==0){
        for(int x =0;x<divisao;x++)
            cout<<inteira<<"\n";
    }
    else{
        int nova_divisa;
        while(resto !=0){
            for(int x =0;x<resto;x++)
                cout<<inteira+1<<"\n";
            quant  -= (inteira+1)*resto;
            nova_divisa = divisao-resto;
            resto   = quant%nova_divisa;
            inteira = quant/nova_divisa;
        }
        for(int x =0;x<nova_divisa;x++)
            cout<<inteira<<"\n";
    }


    return 0;
}