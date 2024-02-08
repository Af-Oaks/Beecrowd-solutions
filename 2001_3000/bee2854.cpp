#include <bits/stdc++.h>

using namespace std;
#define int long long int


int tamanho[3001],parentes[301];

int procurar(int x){

    if(parentes[x]==x) return x;

    return parentes[x] = procurar(parentes[x]);    
}

void uniao(int pessoa1,int pessoa2){

    pessoa1 = procurar(pessoa1);
    pessoa2 = procurar (pessoa2);

    if(tamanho[pessoa1]<pessoa2)
        swap(pessoa1,pessoa2);
    
    tamanho[pessoa1]+=tamanho[pessoa2];
    parentes[pessoa2] = pessoa1;
}


int32_t main(){

    int pessoas,relacoes;
    cin>>pessoas>>relacoes;

    for(int x=0;x<=pessoas;x++){
        parentes[x]=x;
        tamanho[x]=1;
    }

    int pos=1;
    unordered_map<string,int> codigo;
    string nome1,parentesco,nome2;
    for(int x=0;x<relacoes;x++){
        cin>>nome1>>parentesco>>nome2;
        if(codigo[nome1]==0){
            codigo[nome1]=pos;
            pos++;
        }
        if(codigo[nome2]==0){
            codigo[nome2]=pos;
            pos++;
        }
        uniao(codigo[nome1],codigo[nome2]);
    }

    set<int> resp;
    for(int x=1;x<=pessoas;x++){
        procurar(x);
        resp.insert(parentes[x]);
    }
    
    cout<<resp.size()<<"\n";


    return 0;
}