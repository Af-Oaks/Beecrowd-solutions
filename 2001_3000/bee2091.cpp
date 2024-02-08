#include <bits/stdc++.h>

using namespace std;
#define int long long int


int32_t main(){

    int quant,carry;
    while(cin>>quant){
        if(quant ==0)
            break;
        set<int> numeros;
        while(quant--){
            cin>>carry;
            if(numeros.count(carry) ==0)
                numeros.insert(carry);
            else
                numeros.erase(carry);
        }
        for(auto a : numeros)
            cout<<a<<"\n";

    }
    return 0;
}