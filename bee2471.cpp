#include <bits/stdc++.h>

using namespace std;

/*
    solucao dinamica:
    percorrer a matriz coluna por coluna e linha por linha até ver quais sao os diferentes
    a linha e coluna com soma diferente das outras é o numero alvo!
*/


int main(){

    int tam,carry;
    cin>>tam;
    int matriz[tam+1][tam+1];
    
    vector<int> linhas(tam,0),colunas(tam,0);//inicializo com 0
    // no for abaixo eu preencho a matriz da seguinte forma
    /*
        1 2 3 
        4 5 6 
        7 8 9
        vetor[y] quando y for 0 estou sempre adicionando a soma da coluna 0 na posicao 0 do vetor!
        de forma analoga e mais facil é as linhas
        onde quando x =0 adiciona a soma da linha 0 na posicao 0 do vetor
    */
    for(int x=0;x<tam;x++){
        for(int y=0;y<tam;y++){
            cin>>carry;
            matriz[x][y]=carry;
            linhas[x]+=carry;//adicionando no vetor
            colunas[y]+=carry;
        }
    }
    //crio sets para saber quais as somas diferentes nas colunas e linhas
    multiset<int> mset;
    set<int> set;
    int soma_dif,soma_certa;
    for(auto a : linhas){
        mset.insert(a);
        set.insert(a);
        soma_dif=a;
        soma_certa=a;
    }
    for(auto a: set){
        if(mset.count(a)<mset.count(soma_dif)){
            soma_dif=a;
        }
        if(mset.count(soma_certa) < mset.count(a)){
            soma_certa=a;
        }
        // printf("mset(%d)=%d | dif=%d |cert=%d\n",a,mset.count(a),soma_dif,soma_certa);
    }
    //agora q eu sei o numero verificar a posicao no vetor!
    int antes_resp,depois_resp,pos_y,pos_x;
    for(int x=0;x<tam;x++){//loop para verificar posicao do numero!
        // printf("%d ",linhas[x]);
        if(linhas[x]==soma_dif){
            pos_x =x;
            break;
        }
    }
    // printf("\n");
    for(int y=0;y<tam;y++){//loop para verificar posicao do numero!
        // printf("%d ",colunas[y]);
        if(colunas[y]==soma_dif){
            pos_y =y;
            break;
        }
    }
    // printf("\n");
    depois_resp = matriz[pos_x][pos_y];
    // printf("cert=%d | dif=%d | mat[%d][%d]=%d\n",soma_certa,soma_dif,pos_x,pos_y,depois_resp);
    if(soma_certa > soma_dif){
        antes_resp = depois_resp +(soma_certa- soma_dif);
    }
    else{
        antes_resp = depois_resp -(soma_dif - soma_certa);
    }
    printf("%d %d\n",antes_resp,depois_resp);
    return 0;
}