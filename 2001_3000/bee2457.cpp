#include <bits/stdc++.h>

using namespace std;
/*
    ler cada palavra por palavra usando string verificar se tem a letra na 
    palavra armazenar num inteiro e depois dividir pela quantia de palavras;
*/

int main(){

    string entrada;
    char letra;
    int com_letra=0,pal_totais=0;

    cin>>letra;
    while(cin>>entrada){

    for(char a : entrada){
        if(letra == a){
            com_letra++;
            break;
        }
    }
        pal_totais++;
    }
    float resposta = ((float)com_letra/(float)pal_totais)*100;
    printf("%.2f\n",resposta);
    return 0;
}
