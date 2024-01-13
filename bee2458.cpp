#include <bits/stdc++.h>

using namespace std;

/*
    questão de algoritmo dinamico a principio

    solucao: precisamos verificar a borda do tabuleiro se existe alguma seta apontando para fora e botamos
                suas posicoes numa pilha...
            caso exista uma seta q aponte para fora na pilha, fazemos o caminho inverso a partir dessa seta
            e diminuimos da quantia de quadrados total do tabuleiro...
    
    obs: a forma de fazer um caminho inverso se assemelha a um bfs, onde temos q ver todas as peças adjacente
        q apontam para o quadrado atual!
*/




int resolver(int tamanho,vector<string> matriz){

    int resposta=tamanho*tamanho;
    stack<pair<int,int>> pilha;
    vector<vector<int>> visitados;//crio uma matriz de visitados para manter registro dos lugares q ja andei
    vector<int> carry(tamanho+1,0);
    for(int x=0;x<tamanho;x++){
        visitados.push_back(carry);
    }

    //rotina para buscar quais setas estao apontando para fora da matriz
    int i=0,j=0;
    for(int x=0;x<tamanho;x++){//parte de cima = ^
        if(matriz[i][j] == 'A'){
            pilha.push(make_pair(i,j));
        }
        j++;
    }
    j--;
    for(int x=0;x<tamanho;x++){//parte da direita = >
        if(matriz[i][j] == '>'){
            pilha.push(make_pair(i,j));
        }
        i++;
    }
    i--;
    for(int x=0;x<tamanho;x++){//parte de baixo = V
        if(matriz[i][j] == 'V'){
            pilha.push(make_pair(i,j));
        }
        j--;
    }
    j++;
    for(int x=0;x<tamanho;x++){//parte da esquerda = <
        if(matriz[i][j] == '<'){
            pilha.push(make_pair(i,j));
        }
        i--;
    }

    //uma vez verificado quais lugares apontam para fora iremos fazer o caminho reverso alá bfs
    pair<int,int> posicao;
    while(!pilha.empty()){
        posicao = pilha.top();
        pilha.pop();
        //printf("(%d,%d)-",posicao.first,posicao.second);
        if(visitados[posicao.first][posicao.second] == 0){// se n foi visitado entao verifico os adjacentes e diminui a posicao de quadrados validos
            resposta--;
            visitados[posicao.first][posicao.second] =1;
            if(posicao.first+1<tamanho){
                //printf("Baix");
                if(matriz[posicao.first+1][posicao.second] == 'A' && visitados[posicao.first+1][posicao.second] ==0){//se abaixo de mim aponta pra cima
                    pilha.push(make_pair(posicao.first+1,posicao.second));
                }
            }
            if(posicao.first -1>=0){
               // printf("Cima");
                if(matriz[posicao.first-1][posicao.second] == 'V' && visitados[posicao.first-1][posicao.second] ==0){//se acima de mim aponta pra baixo
                    pilha.push(make_pair(posicao.first-1,posicao.second));
                }
            }
            if(posicao.second+1<tamanho){
                //printf("Dir");
                if(matriz[posicao.first][posicao.second+1] == '<' && visitados[posicao.first][posicao.second+1] ==0 ){// se a minha direita aonta pra esq
                    pilha.push(make_pair(posicao.first,posicao.second+1));
                }
            }
            if(posicao.second-1>=0){
                if(matriz[posicao.first][posicao.second-1] == '>' && visitados[posicao.first][posicao.second-1] ==0 ){//se a minha esq aponta para dir
                    pilha.push(make_pair(posicao.first,posicao.second-1));
                }
            }
        }
    }



    return resposta;
}



int main(){

    int tamanho;
    string carry;
    vector<string>matriz;

    scanf("%d",&tamanho);

    for(int x=0;x<tamanho;x++){
        cin>>carry;
        matriz.push_back(carry);
    }

    printf("%d\n",resolver(tamanho,matriz));


    return 0;
}