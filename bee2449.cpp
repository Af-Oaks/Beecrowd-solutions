#include <bits/stdc++.h>

using namespace std;

/*
   solucao dinamica encontrar 2 pares consecutivos q estejam abaixo do valor da altura
   possivel solucao greedy caso seja possivel  manipular os pinos do extremos separados
   se sim, verificar... GREEDY NAO FUNFA, mas é possivel maniupular os pinox estremo separados
*/
/*
    hipotese, a ordem do problema nao importa, tentar e verificar o porque disso...
    possivel porque: enquanto nao tenhamos q consertar um pino mais de uma vez continuará a ser
    solução otima, pois a diferença de todos as alturas de pinos será feita no ultimo pino
    onde não influenciara os restantes....
*/
int main(){

    int num_chaves,altura,carry1,resposta=0;
    scanf("%d %d",&num_chaves,&altura);

    vector<int> numeros;// crio vetor de pinos
    for(int x=0;x<num_chaves;x++){
        scanf("%d",&carry1);
        numeros.push_back(carry1);//preencho
    }

    for(int x=0;x<num_chaves-1;x++){
        resposta +=  abs(altura - numeros[x]);//soma a resposta a diferenca do pina par altura ideal
        numeros[x+1] += altura - numeros[x];//incremento no pino consecutivo
    }
        resposta+=abs(altura - numeros[num_chaves-1]);//preencho o ultimo pino manualmente
    printf("%d\n",resposta);

    return 0;
}