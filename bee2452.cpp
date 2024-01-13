#include <bits/stdc++.h>

using namespace std;

/*
    soluca: encontrar a maior quantidade de espaço em brancos consecutivos
    se tiver reagente nos dois lados desse espaço resposta = quantia/2
    se nao apenas quantia...
    problema Time exceeded, resolver baseado na diferença entre os valores dos pigmentos
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