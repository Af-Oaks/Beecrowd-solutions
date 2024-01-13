#include <bits/stdc++.h>

using namespace std;

/*
    questao simples apenas um vetor e um unordered_set para verificação otima ods numeros
*/


int main(){

    int carry,quant=0;
    unordered_set<int> sorteados;
    vector<int> aposta;
    for(int x=0;x<6;x++){
        cin>>carry;
        aposta.push_back(carry);
    }
    for(int x=0;x<6;x++){
        cin>>carry;
        sorteados.insert(carry);
    }

    for(auto a : aposta){
        if(sorteados.count(a))
            quant++;
    }

    if(quant<=2)
        printf("azar\n");
    if(quant==3)
        printf("terno\n");
    if(quant==4)
        printf("quadra\n");
    if(quant==5)
        printf("quina\n");
    if(quant==6)
        printf("sena\n");

    return 0;
}