#include <bits/stdc++.h>

using namespace std;

/*
    algoritmo dinamico de leitura
*/

int main(){

    int tam_m,carry;
    int init_x,init_y;
    cin>>tam_m;
    cin>>init_x>>init_y;
    init_x--;init_y--;
    int matrix[tam_m+1][tam_m+1];
    int visitados[tam_m+1][tam_m+1];
    for(int x;x<tam_m;x++){
        for(int y=0;y<tam_m;y++){
            cin>>carry;
            matrix[x][y] = carry;
            visitados[x][y]=0;
        }
    }

    int bandeiras=1;
    visitados[init_x][init_y] =1;
    int last_x=init_x,last_y=init_y;
    stack<pair<int,int>> pilha;
    pilha.push({init_x,init_y});
    pilha.push({init_x,init_y});
    pilha.push({init_x,init_y});
    pilha.push({init_x,init_y});
    while(!pilha.empty()){
        //cima
        //printf("matriz[%d][%d]= %d\n",init_x+1,init_y+1,matrix[init_x][init_y]);
        if(init_x-1>=0 && matrix[init_x][init_y] <= matrix[init_x-1][init_y] && visitados[init_x-1][init_y] ==0){
            visitados[init_x-1][init_y] =1;
            init_x-=1;
            pilha.push({init_x,init_y});
            pilha.push({init_x,init_y});
            pilha.push({init_x,init_y});
            pilha.push({init_x,init_y});
            bandeiras++;
        }
        //direita
        else if(init_y+1<tam_m && matrix[init_x][init_y] <= matrix[init_x][init_y+1] && visitados[init_x][init_y+1] ==0){
            visitados[init_x][init_y+1] =1;
            init_y+=1;
            pilha.push({init_x,init_y});
            pilha.push({init_x,init_y});
            pilha.push({init_x,init_y});
            pilha.push({init_x,init_y});
            bandeiras++;
        }
        //baixo
        else if(init_x+1<tam_m && matrix[init_x][init_y] <= matrix[init_x+1][init_y] && visitados[init_x+1][init_y] ==0){
            visitados[init_x+1][init_y] =1;
            init_x+=1;
            pilha.push({init_x,init_y});
            pilha.push({init_x,init_y});
            pilha.push({init_x,init_y});
            pilha.push({init_x,init_y});
            bandeiras++;
        }
        //esquerda
        else if(init_y-1>=0 && matrix[init_x][init_y] <= matrix[init_x][init_y-1] && visitados[init_x][init_y-1] ==0){
            visitados[init_x][init_y-1] =1;
            init_y-=1;
            pilha.push({init_x,init_y});    
            pilha.push({init_x,init_y});
            pilha.push({init_x,init_y});
            pilha.push({init_x,init_y});
            bandeiras++;
        }
        else{//devolver!
            init_x= pilha.top().first;
            init_y = pilha.top().second;
            pilha.pop();
        }
    }

    printf("%d\n",bandeiras);

    return 0;
}