#include <bits/stdc++.h>

using namespace std;

/*
    soluca: resolver baseado na diferença entre os valores dos pigmentos
            se o espaço entre pigmentos é 10, entao o tempo gasto é a metade disso
            exeção para os cantos onde o tempo gasto é o valor integral
            apos isso verficar qual o maior valor encontrado
    
*/

int main(){

    int tamanho,quantia_reag,carry,last=1,sequencia=0;
    int resposta=0,left=0;
    scanf("%d %d",&tamanho,&quantia_reag);

    for(int x=0;x<quantia_reag;x++){
        scanf("%d",&carry);
        sequencia = carry -last;
        if(sequencia/2>resposta && left){
            resposta = sequencia/2;
        }
        else if(sequencia>resposta && !left){
            resposta = sequencia;
        }
        left=1;
        last=carry;
    }
    sequencia = tamanho - last;
    if(sequencia>resposta)
        resposta = sequencia;
    printf("%d\n",resposta);

    return 0;
}