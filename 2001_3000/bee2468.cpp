#include <bits/stdc++.h>

using namespace std;

/*
    possivelmente questão de combinatoria...
    ou problema de AGM??? fazendo verificações enquanto insere as aresta?
    A principio o problema é de combinatoria, onde devemos descobrir todas as esquinas que 
    possuem uma esquina bonita entre elas, então nos aproveitando do algoritmo de kruskal
    inserimos todas as ruas q não sao bonitas primeiros, assim gerando grafos incompletos
    e apos inserimos somente as ruas bonitas onde ao juntarmos dois grafos a quantidade de
    esquinas que tem uma rua bonita entre eleas sao a multiplicacao do tamanho desses
    dois grafos que foram unidos!
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
long long int uniao(int a,int b,int* link,int* size,int bonita){

    a = procurar(a,link);
    b = procurar(b,link);
    long long int possibilidades =0;
    if(bonita){
        long long int ladoa = size[a],ladob=size[b];
        possibilidades += ladoa * ladob;
    }

    if(size[a] < size[b]){
        swap(a,b);
    }

    size[a]+=size[b];//somamos o tamanho dos subsets diferentes
    link[b]=a;// nomeamos apenas um pai para ele

    return possibilidades;
}

long long int kruskal(int n_cidade,vector<tuple<int,int,int>> list_adj){
    long long int resposta =0;

    int *unidos,*tamanho;
    tamanho = (int*)malloc(sizeof(int)* (n_cidade+2));
    unidos = (int*)malloc(sizeof(int)* (n_cidade+2));

    for(int x=0;x<=n_cidade;x++){
        tamanho[x] = 1;//todas as arvores tem tamanho 1
        unidos[x]  = x;//todas as arvores sao unidas apenas consigo mesmas.
    }
    sort(list_adj.begin(),list_adj.end(),ordenar_3_termo);//ordenando as conexoes por custo
    //rodamos o algoritmo primeiramente para ferrovias independente se o há rodovias com custo menor
    for(tuple<int,int,int> conexao : list_adj){
        if(!iguais(conexao,unidos)){
            resposta += uniao(get<0>(conexao),get<1>(conexao),unidos,tamanho,get<2>(conexao));
        }
    }

    return resposta;
}

int main(){

    int tamanho,c1,c2,c3;

    cin>>tamanho;
    vector<tuple<int,int,int>>lista;
    for(int x=0;x<tamanho-1;x++){
        cin>>c1>>c2>>c3;
        lista.push_back(make_tuple(c1,c2,c3));
    }

    printf("%lld\n",kruskal(tamanho,lista));

    return 0;
}