#include <bits/stdc++.h>

using namespace std;

int *distancias;
bool *visitados;

int dijkstra(vector<vector<int16_t>> lista_adj,vector<vector<int16_t>> lista_term,int origem,int dest,int quant_nos){

    memset(visitados,0,quant_nos+1);

    for(int x =0;x<quant_nos+1;x++){
        distancias[x] = 10001;
    }

    distancias[origem]=0;
    stack<int> pilha;
    pilha.push(origem);

    while(!pilha.empty()){
        int new_pos = pilha.top();
        pilha.pop();

        if(visitados[new_pos]==0){
            visitados[new_pos] =1;

            int alt_len = distancias[new_pos];

            for(auto a : lista_adj[new_pos]){
                for(auto b : lista_term[a])
                if(alt_len + 1 < distancias[b]){
                    distancias[b] = alt_len +1;
                    pilha.push(b);    
                }
            }
        }
    }
    return distancias[dest];
}

int32_t main(){

    int quant_terminais,num_onibus,inicio,destino;
    cin>>quant_terminais>>num_onibus>>inicio>>destino;
    vector<vector<int16_t>> lista_adj,lista_linha_term;
    distancias = (int*)malloc(sizeof(int)*(quant_terminais+1));
    visitados = (bool*)malloc(sizeof(bool)*(quant_terminais+1));

    lista_adj.resize(quant_terminais+1);
    lista_linha_term.resize(num_onibus+1);
    int carry1,carry2;
    for(int x=0;x<num_onibus;x++){
        cin>>carry1;
        vector<int> aux;
        for(int z=0;z<carry1;z++){
            cin>>carry2;
            lista_adj[carry2-1].push_back(x);//quais terminais tem quais linhas disponiveis!
            lista_linha_term[x].push_back(carry2-1);
        }
    }

    cout<<dijkstra(lista_adj,lista_linha_term,inicio-1,destino-1,quant_terminais)<<"\n";

    return 0;
}