#include <bits/stdc++.h>

using namespace std;

/*
    simples trabalho de acesso de uma estrutura de dados para troca das letras

*/

int main(){

    string cifra,frase;
    cin>>cifra>>frase;
    for(int x=0;x<frase.size();x++){
        frase[x] = cifra[ (int)frase[x]-97];
    }
    cout<<frase<<"\n";
    return 0 ;
}