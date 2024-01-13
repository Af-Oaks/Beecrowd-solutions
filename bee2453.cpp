#include <bits/stdc++.h>

using namespace std;

/*
    como há sempre uma letra p antes de cada letra e há uma logo no começo
    precisamos apenas pegar as posicoes impares do vetor string

    pUpm pfpiplpmpe plpepgpapl

*/

int main(){

    string entrada;
    int espaco=0;
    while(cin>>entrada){
        string resposta;
        int troca=1;
        if(espaco){
            cout<<" ";
        }

        for(char a : entrada){
            if(troca){
                troca=0;
            }
            else{
                resposta.push_back(a);
                troca=1;
            }
        }
        espaco =1;
        cout<<resposta;
    }
    printf("\n");
    return 0;
}