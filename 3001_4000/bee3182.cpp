#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main(){

    int part,orcamento,hoteis,semanas;
    cin>>part>>orcamento>>hoteis>>semanas;

    int valid=0,menor_cust = INT32_MAX,carry1,carry2;
    for(int x=0;x<hoteis;x++){
        cin>>carry1;
        for(int x=0;x<semanas;x++){
            cin>>carry2;
            if(carry1*part<= orcamento && part<= carry2 && menor_cust>carry1*part){
                valid= 1;
                menor_cust = carry1*part;
            }
        }
    }
    if(valid){
        cout<<menor_cust<<"\n";
    }
    else
    cout<<"stay home\n";


    return 0;
}