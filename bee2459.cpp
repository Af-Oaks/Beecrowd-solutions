#include <bits/stdc++.h>

using namespace std;
/*
   possivelmente é um problema de arvore geradora minima
   algoritmo de kruskal...
   entretanto temos q adaptar o algoritmo de forma a seguir os criterios do problema
   de forma sequencial
    1- condição.. ser possivel sair de uma cidade a outra usando apenas estra/ferrovi
        reformadas(avore geradora minima)
    2- priorizar a criação de ferrovias
    3- e finalmente ir pelo custos das reformas...

*/

int ordenar_3_termo(tuple<int,int,double> a,tuple<int,int,double> b){
    return get<2>(a) < get<2>(b);
}
int procurar(int x,int*link){
    while(x != link[x]){
        x=link[x];
    }
    return x;    
}
int iguais(tuple<int,int,double> edge,int*link){

    return procurar(get<0>(edge),link) == procurar(get<1>(edge),link);
}
void uniao(int a,int b,int* link,int* size){

    a = procurar(a,link);
    b = procurar(b,link);

    if(size[a] < size[b]){
        swap(a,b);
    }
    size[a]+=size[b];//somamos o tamanho dos subsets diferentes
    link[b]=a;// nomeamos apenas um pai para ele

}

int kruskal(int n_cidade,vector<tuple<int,int,int>> ferrovia,vector<tuple<int,int,int>> rodovia){
    int resposta =0;

    int *unidos,*tamanho;
    tamanho = (int*)malloc(sizeof(int)* (n_cidade+2));
    unidos = (int*)malloc(sizeof(int)* (n_cidade+2));

    for(int x=0;x<=n_cidade;x++){
        tamanho[x] = 1;//todas as arvores tem tamanho 1
        unidos[x]  = x;//todas as arvores sao unidas apenas consigo mesmas.
    }

    sort(ferrovia.begin(),ferrovia.end(),ordenar_3_termo);//ordenando as conexoes por custo
    sort(rodovia.begin(),rodovia.end(),ordenar_3_termo);

    //rodamos o algoritmo primeiramente para ferrovias independente se o há rodovias com custo menor

    for(tuple<int,int,int> conexao : ferrovia){
        if(!iguais(conexao,unidos)){
            uniao(get<0>(conexao),get<1>(conexao),unidos,tamanho);
            resposta+=get<2>(conexao);
        }
    }

    //rodamos o algoritmo agora para as rodovias 
    //caso a arvore minima q conecta todos os pontos já existe, o custo não será alterado por essa parte
    
    for(tuple<int,int,int> conexao : rodovia){
        if(!iguais(conexao,unidos)){
            uniao(get<0>(conexao),get<1>(conexao),unidos,tamanho);
            resposta+=get<2>(conexao);
        }
    }
    return resposta;
}

int main(){

    int n_cidade,num_ferrovias,num_rodovias;
    int carry1,carry2,carry3;
    vector<tuple<int,int,int>> ferrovias,rodovias; // lista de adjacencia com peso
    scanf("%d %d %d",&n_cidade,&num_ferrovias,&num_rodovias);

    for(int x=0;x<num_ferrovias;x++){
        scanf("%d %d %d",&carry1,&carry2,&carry3);
        ferrovias.push_back(make_tuple(carry1,carry2,carry3));
    }
    for(int x=0;x<num_rodovias;x++){
        scanf("%d %d %d",&carry1,&carry2,&carry3);
        rodovias.push_back(make_tuple(carry1,carry2,carry3));
    }

    printf("%d\n",kruskal(n_cidade,ferrovias,rodovias));

    return 0;
}