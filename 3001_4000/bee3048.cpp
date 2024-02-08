#include <bits/stdc++.h>

using namespace std;
#define int long long int

int32_t main(){

    int count =1,quant,carry,troca=1;
    cin>>quant;
    while(quant--){
        cin>> carry;
        if(carry != troca){
            troca = carry;
            count++;
        }
    }
    cout<<count<<"\n";


    return 0;
}