#include <bits/stdc++.h>

using namespace std;

/*
    questão: algoritmo dinamico
    solução: criar um map q mantem o codigo das pessoas na fila com sua reespectiva posicao na fila
    assim nao precisa se preocupar com ordenar um vetor, so retirar os elementos e ordenar baseado no segundo elemento
*/

int main(){

    int quant_init,carry,quant_rem,carry2;
    cin>>quant_init;
    map<int,int> mapa_ordem,mapa_chave;
    for(int x=0;x<quant_init;x++){
        cin>>carry;
        mapa_ordem[x]=carry;
        mapa_chave[carry] =x;
    }
    cin>>quant_rem;
    for(int x=0;x<quant_rem;x++){
        cin>>carry;
        carry2 = mapa_chave[carry];//pego a posicao de quem tenho q remover
        mapa_ordem.erase(carry2);
    }
    int cond =0;
    for(auto a : mapa_ordem){
        cout<<a.second;
        if(cond <quant_init-quant_rem-1){
            cout<<" ";
        }
        cond++;
    }
    printf("\n");


    return 0;
}