#include <bits/stdc++.h>

using namespace std;
#define int long long int

int32_t main(){

    long double montante,doar,rendimento,custo_mensal;
    cin>>montante>>doar>>rendimento>>custo_mensal;
    doar/=100.0;rendimento/=100.0;

    int meses = floorl( log10l(custo_mensal/(montante*rendimento))/log10l(1.0-doar));
    if(meses>=0)
        printf("%d\n",meses);
    else
        printf("0\n");


    return 0;
}