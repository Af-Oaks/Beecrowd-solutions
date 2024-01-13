#include <bits/stdc++.h>

using namespace std;

/*
    solucao usar um dicionario para retirada da distancia e calcular a diferenca
    a partir de uma variavel q guarda a ultima posicao do carteiro

*/

int main(){

    queue<int> encomendas;
    int last_pos,carry1,carry2,n,m,resposta=0;
    carry1=0;
    scanf("%d %d",&n,&m);
    map<int,int> casas;
    for(int x=0;x<n;x++){
        scanf("%d",&carry2);
        casas.insert({carry2,carry1});
        carry1++;
    }
    for(int x=0;x<m;x++){
        scanf("%d",&carry2);
        encomendas.push(carry2);
    }
    last_pos=0;
    while(!encomendas.empty()){
        carry1 = encomendas.front();
        // printf("carry1 = %d",carry1);
        carry1 = casas[carry1];
        // printf(" =>%d ||",carry1);
        resposta += abs(carry1 - last_pos);
        // printf("resp=%d || abs( %d - %d) \n",resposta,carry1,last_pos);
        encomendas.pop();
        last_pos = carry1;
    }

    printf("%d\n",resposta);

    return 0;
}