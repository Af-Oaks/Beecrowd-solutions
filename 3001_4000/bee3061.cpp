#include <bits/stdc++.h>

using namespace std;
// #define int long long int
int **matriz,**visitados;
int countar =0;

void bfs(int x,int y,int linhas,int colunas){

    if(visitados[x][y]==1 || matriz[x][y]==0)
        return;
    stack<pair<int,int>> pilha;

    pilha.push({x,y});

    while(!pilha.empty()){
        pair<int,int> pos=pilha.top();
        pilha.pop();
        if(pos.first+1 <=linhas){
            if(matriz[pos.first+1][pos.second] ==1 && visitados[pos.first+1][pos.second] ==0 ){
                visitados[pos.first+1][pos.second] =1;
                pilha.push({pos.first+1,pos.second });
            }
        }
        if(pos.first-1 >0){
            if(matriz[pos.first-1][pos.second] ==1 && visitados[pos.first-1][pos.second] ==0 ){
                visitados[pos.first-1][pos.second] =1;
                pilha.push({pos.first-1,pos.second });
            }
        }
        if(pos.second+1<=colunas){
            if(matriz[pos.first][pos.second+1] ==1 && visitados[pos.first][pos.second+1] ==0 ){
                visitados[pos.first][pos.second+1] =1;
                pilha.push({pos.first,pos.second+1});
            }
        }
        if(pos.second-1>0){
            if(matriz[pos.first][pos.second-1] ==1 && visitados[pos.first][pos.second-1] ==0 ){
                visitados[pos.first][pos.second-1] =1;
                pilha.push({pos.first,pos.second-1});
            }
        }
    }
    countar++;
}

int32_t main(){

    int linhas,colunas;
    cin>>linhas>>colunas;
    matriz = (int**)malloc(sizeof(int*)*(linhas+2));
    visitados=(int**)malloc(sizeof(int*)*(linhas+2));

    for(int x=1;x<=linhas;x++){
        matriz[x]= (int*)malloc(sizeof(int)*(colunas+2));
        visitados[x]=(int*)malloc(sizeof(int)*(colunas+2));
        memset(matriz[x],0,colunas+2);
        memset(visitados[x],0,colunas+2);

        for(int z=1;z<=colunas;z++){
            cin>>matriz[x][z];
            visitados[x][z]=0;
        }
    }
    for(int x=1;x<=linhas;x++){
        for(int z=1;z<=colunas;z++){
            bfs(x,z,linhas,colunas);
        }
    }
    cout<<countar<<"\n";
    return 0;
}