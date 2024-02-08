#include <bits/stdc++.h>

using namespace std;

/*
    solucao greedy pois o custo escala com a area do tapete onde é n²
*/

int main(){

    long long int compr,quant;
    cin>>compr>>quant;

    vector<long long int> tapetes(quant,1);

    int stop=1,pos=0;
    while(quant<compr && stop){
        stop=0;
        if(tapetes[pos]<=compr-quant){
            stop=1;
            long long int ate=1;
            while(ate <= (compr-quant)+1){
                ate++;
            }
            ate--;
            quant+= ate -tapetes[pos];
            tapetes[pos]=ate*ate;
            pos++;
        }
    }
    long long int resposta=0;
    for(auto a : tapetes)
        resposta+=a;
    printf("%lld\n",resposta);
    return 0;
}