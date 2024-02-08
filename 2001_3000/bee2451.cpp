#include <bits/stdc++.h>

using namespace std;

/*
    apenas ir percorrendo e salvar numa variavel a maior quantiade comida
    encontrada antes de bater num fantasma ao percorrer a matriz de 
    acordo com o problema
*/

int main(){

    int maior_comida =0,comida_atual=0,troca=1,tamanho;
    cin>>tamanho;
    string entry;

    for(int x=0;x<tamanho;x++){
        cin>>entry;
        for(int z=0;z<tamanho;z++){
            if(troca ==1){
                if(entry[z] == 'o'){
                    comida_atual +=1;
                }
                if(entry[z] == 'A'){
                    if(comida_atual> maior_comida){
                        maior_comida = comida_atual;
                    }
                    comida_atual =0;
                }
            }
            else{
                if(entry[tamanho -z -1] == 'o'){
                    comida_atual +=1;
                }
                if(entry[tamanho -z -1] == 'A'){
                    if(comida_atual > maior_comida){
                        maior_comida = comida_atual;
                    }
                    comida_atual =0;
                }
            }
        } 
        troca *=-1;//troco a ordem de preencher 
        //leio o vetor linha normalmente sempre da esq->dir
    }

    if(maior_comida< comida_atual)//checagem final se a nao sair do jogo compensa
        maior_comida = comida_atual;

    printf("%d\n",maior_comida);

    return 0;
}