#include <bits/stdc++.h>
using namespace std;
/*
    questão algoritmo dinamico°??
    a principio temos q construir 1 lista para o conjuto A, e um set para o conjuto B
    fazemos as seguintes rotinas;
    criamos um novo set baseado nos numeros faltantes do conjunto A em B.
    assim teremos 2 sets: 1- com os numeros gerados apenas pelas somas dos proprios numeros em B
                        : 2- com todos o snumero do conjuto A q estão em B,
                    restando apenas como verificar de uma forma eficiente se as conbinações do 1 geram o 2... 
*/

int main(){
    int a,b,carry,nao_achou=1;
    int soma=0,blefe=0,numero_falso=0;
    cin>>a>>b;

    unordered_set<int> verificacao,conj_a;

    for(int x=0;x<a;x++){
        cin>>carry;
        conj_a.insert(carry);// preenchendo o conjunto a
    }

    //agora itero por b elementos
    for(int x=0;x<b;x++){
        cin>>carry;
        if(conj_a.find(carry) != conj_a.end()){//se a propria entrada é um numero do conjunto A
            verificacao.insert(carry);
            nao_achou =0;
        }
        else if(verificacao.find(carry/2) != verificacao.end() && carry%2 ==0){// verifico se existe a metade do elemento
            verificacao.insert(carry);
            nao_achou=0;
        }     
        else{
            for(int a : verificacao){
                soma = carry - a;// verifico nos numeros anteriores a subtracao dele(o numero original antes da soma)
                if(verificacao.find(soma) != verificacao.end()){//se esse numero existe no conjunto b
                    verificacao.insert(carry);
                    nao_achou=0;
                    break;
                }
            }
        }
        if(nao_achou){
                blefe=1;
                numero_falso =carry;
                goto end;
        }
        nao_achou =1;
    }
    end:
        if(blefe==0){
            printf("sim\n");
        }
        else{
            printf("%d\n",numero_falso);
        }

    return 0;
}