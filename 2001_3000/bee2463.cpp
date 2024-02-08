#include <bits/stdc++.h>

using namespace std;

/*
    problema: encontrar a maior subsequencia de numeros em uma sequencia....
        usando meu algoritmo q rodaria em log(N) mas n funfa de analisar a sequencia de 3 termos
        apos a filtração em apenas numeros -+-+-+-+-+ nao funciona(nao sei o pq)
    
    descoberto que esse problema é o caso do Kadane's algorithm
        cuja rodaria em log(N) usando apenas duas variaveis
    


*/

int main(){

    int entrada,carry,maior=0,atual=0;
    cin>>entrada;

    for(int x=0;x<entrada;x++){
        cin>>carry;
        atual+=carry;
        if(atual<0)
            atual =0;
        if(maior<atual)
            maior =atual;
    }

    printf("%d\n",maior);

    return 0;

}