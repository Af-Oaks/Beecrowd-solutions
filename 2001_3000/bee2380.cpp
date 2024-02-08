#include <bits/stdc++.h>

using namespace std;

int tamanho[100001],fusao[100001];

int procurar(int x){

    if(fusao[x]==x) return x;

    return fusao[x] = procurar(fusao[x]);    
}

void uniao(int banco1,int banco2){

    banco1 = procurar(banco1);
    banco2 = procurar (banco2);

    if(tamanho[banco1]<banco2)
        swap(banco1,banco2);
    
    tamanho[banco1]+=tamanho[banco2];
    fusao[banco2] = banco1;
}

int main(){

    int bancos, consultas,cb1,cb2;
    cin>>bancos>>consultas;

    for(int x=0;x<bancos+1;x++){
        tamanho[x]=1;
        fusao[x]=x;
    }
    char letra;
    for(int x=0;x<consultas;x++){
        cin>>letra>>cb1>>cb2;
        switch(letra){

            case 'C':
                ( procurar(cb1) == procurar(cb2)) ?cout<<"S\n" : cout<<"N\n";
                break;

            case 'F':
                uniao(cb1,cb2);
                break;
        }

    }

return 0;
}