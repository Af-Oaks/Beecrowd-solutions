#include <bits/stdc++.h>
using namespace std;
/*
    ad-hoc
    a principio temos q construir 2 unordered_set, um para o conj a e outro para o conjunto B.
    a sacada está em ir verificando a medida q recebemos os elementos de entrada, pois quanto maior o conjunto
    pior o tempo gasto da verificação.
    ademais, devemos criar certas rotinas para otimizar o tempo de analise.
    1- se a propria entrada já está no conjunto A.
    2- se metade do valor já existe no conjunto verificacao(conjunto b)
    3- somente apos isso verificar se a diferença desse numero entre os numeros do conjunto verificacao existe em A.
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