#include <bits/stdc++.h>

using namespace std;

/*
    solução algoritmo dinamico
    Algoritmo dinamico usando dois vetores para troca da base.
    1 vetor recebe a entrada principal do problema e baseado nele criamos o segundo vetor
    respeitando as regras do problema, apos isso o vetor principal recebe o segundo vetor
    e repetimos até o vetor ter tamanho 1

*/

int main(){
    
    int tam_base,carry;
    vector<int> base;
    cin>>tam_base;
    for(int x=0;x<tam_base;x++){
        cin>>carry;
        base.push_back(carry);
    }

    while(base.size()>1){
        vector<int> troca;

        for(int x=0;x<base.size()-1;x++){
            if(base[x] + base[x+1] == 0){
                troca.push_back(-1);
            }
            else{
                troca.push_back(1);
            }
        }
        base=troca;
    }

    if(base[0]== 1){
        printf("preta\n");
    }
    else
        printf("branca\n");

    return 0;
}