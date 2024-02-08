#include <bits/stdc++.h>

using namespace std;
#define int long long int

struct compare
{
    bool operator()(const pair<int,int> &a, const pair<int,int> & b)
    {
        return a.second > b.second;
    }
};

int dijkstra(vector<vector<pair<int,int>>> lista_adj,int origem,int dest,int quant_nos){

    vector<int> distancias,visitados(quant_nos+1,0);
    for(int x =0;x<quant_nos+1;x++){
        distancias.push_back(INT32_MAX);
    }

    distancias[origem]=0;

    priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pilha;

    pilha.push({origem,0});

    while(!pilha.empty()){
        pair<int,int> new_pos = pilha.top();
        pilha.pop();

        if(visitados[new_pos.first]==0){
            visitados[new_pos.first] =1;

            int alt_len = distancias[new_pos.first];

            for(auto a : lista_adj[new_pos.first]){
                if(alt_len + a.second < distancias[a.first]){
                    distancias[a.first] = alt_len +a.second;
                    pilha.push({a.first,alt_len + a.second});    
                }
            }
        }
    }


    return distancias[dest];
}

int32_t main(){
    //usar dijkstra!
    int num_nos,num_ligas,pos1,pos2,carry1,carry2;
    cin>>num_nos>>num_ligas>>pos1>>pos2;
    vector<vector<pair<int,int>>> lista_adj(num_nos+1);
    for(int x=0;x<num_ligas;x++){
        cin>>carry1>>carry2;
        lista_adj[carry1].push_back({carry2,0});
        lista_adj[carry2].push_back({carry1,1});
    }
    int bibi= dijkstra(lista_adj,pos1,pos2,num_nos);
    int bibika = dijkstra(lista_adj,pos2,pos1,num_nos);

    if(bibi == bibika){
        cout<<"Bibibibika\n";
    }
    else if(bibi<bibika){
        cout<<"Bibi: "<<bibi<<"\n";}
    else if(bibika!= INT32_MAX){
        cout<<"Bibika: "<<bibika<<"\n";}
    else
        cout<<"Bibibibika\n";

    return 0;
}