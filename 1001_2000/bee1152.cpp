#include <bits/stdc++.h>

using namespace std;
#define int long long int

int ordenar_3_termo(tuple<int,int,int> a,tuple<int,int,int> b){
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

int kruskal(int n_cidade,vector<tuple<int,int,int>> list_adj){
    int resposta =0;

    int *unidos,*tamanho;
    tamanho = (int*)malloc(sizeof(int)* (n_cidade+2));
    unidos = (int*)malloc(sizeof(int)* (n_cidade+2));

    sort(list_adj.begin(),list_adj.end(),ordenar_3_termo);//ordenando as conexoes por custo

    for(int x=0;x<=n_cidade;x++){
        tamanho[x] = 1;//todas as arvores tem tamanho 1
        unidos[x]  = x;//todas as arvores sao unidas apenas consigo mesmas.
    }

    //rodamos o algoritmo primeiramente para ferrovias independente se o há rodovias com custo menor
    for(tuple<int,int,int> conexao : list_adj){
        if(!iguais(conexao,unidos)){
            resposta += get<2>(conexao);
            uniao(get<0>(conexao),get<1>(conexao),unidos,tamanho);
        }
    }

    return resposta;
}

int32_t main(){

    int tamanho,nos,c1,c2,c3;

    while(cin>>nos>>tamanho){
        if(tamanho == 0 && nos ==0)
            break;
        vector<tuple<int,int,int>>lista;
        int total =0;
        for(int x=0;x<tamanho;x++){
            cin>>c1>>c2>>c3;
            total+=c3;
            lista.push_back(make_tuple(c1,c2,c3));
        }

        printf("%lld\n",total-kruskal(nos,lista));
    }


    return 0;
}