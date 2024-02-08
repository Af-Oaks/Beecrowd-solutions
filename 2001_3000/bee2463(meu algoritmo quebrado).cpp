#include <bits/stdc++.h>

using namespace std;

/*
    problema: encontrar a maior subsequencia de numeros em uma sequencia....


*/

int main(){

    int entrada,carry,current,last_max,mode;
    cin>>entrada;
    vector<int> vidas;
    current =0;mode=1;
    for(int x=0;x<entrada;x++){
        cin>>carry;
        if(mode ==1){
            if(carry>=0){
                current+=carry;
            }
            else{
                vidas.push_back(current);
                current =carry;
                mode =0;
            }
        }
        else{
            if(carry <=0){
                current+=carry;
            }
            else{
                vidas.push_back(current);
                current =carry;
                mode =1;
            }
        }
    }

    while(vidas[0] <=0){
        vidas.erase(vidas.begin());
    }
    vidas.push_back(current);
    //algoritmo redutivo se eu tenho um vetor {92,-35,2,-60,35,-1,71} apos a filtração ao inserir os elementos no vetor
    //eu irei olhar uma sequencia de 3 elementos consecutivos.. se a soma deles for maior q o valor individual dos 2 numeros positos separados então eu simplifico o vetor
    // e rodo o algorimto até percorrer o vetor por completo sem ocorrer nenhuma modificação
    int last_size = vidas.size()+1;
    int first,meio,fim;
        for(auto a : vidas){
            printf("%d ",a);
        }
        printf("\n");
    while(last_size != vidas.size()){
        last_size = vidas.size();
        vector<int> troca;//inicializo um vetor novo complementar para o algoritmo
        int last_x=0;
        for(int x=0;x<vidas.size()-2;x++){
            printf("entrei |");
            first= vidas[x]; meio = vidas[x+1]; fim = vidas[x+2];
            if(first +meio+fim >=first && first+meio+fim >= fim){
                troca.push_back(first+meio+fim);
                x+=2;
                last_x=x+1;
            }
            // else if(){
            // }
            else{
                troca.push_back(first);
                last_x=x+1;
            }
            
        }

        while(last_x<vidas.size()){
            printf(" | last=%d |",last_x);
            troca.push_back(vidas[last_x]);
            last_x++;
        }
        //printf("vidas=%d || troca =%d \n",vidas.size(),troca.size());
        vidas = troca;//passo a nova versão reduzida para o vidas;
        for(auto a : vidas){
            printf("%d ",a);
        }
        printf("\n");
    }

    //reagrupamento caso fique algum caso de numeros pares sequenciais sobrandos

    for(int x=0;x<vidas.size()-1;x++){
        if(vidas[x]>=0 && vidas[x+1] >=0){
            vidas[x] = vidas[x]+vidas[x+1];
            vidas.erase(vidas.begin()+x+1);
            x--;
        }
    }


    //apos a redução procuro somente o maior elemento do vetor
    int maior =0;
    for(auto a: vidas){
        if(a>maior)
            maior=a;
    }

    printf("%d\n",maior);

    return 0;

}