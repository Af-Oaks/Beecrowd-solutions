#include <bits/stdc++.h>

using namespace std;
#define int long long int

int32_t main(){

    vector<string> matriz;
    int prof,larg,pos=0;
    cin>>prof>>larg;
    matriz.resize(prof);
    for(int x=0;x<prof;x++)
        cin>>matriz[x];

    for(auto a : matriz[0]){
        if(a =='o'){
            break;
        }
        pos++;
    }
    int pf=0;
    queue<pair<int,int>> fila;
    fila.push({pos,0});
    while(!fila.empty()){
        pair<int,int> atual = fila.front();
        fila.pop();
        if(atual.first-1>=0 && atual.second<prof-1){
            if(matriz[atual.second][atual.first-1] == '.' && matriz[atual.second+1][atual.first] == '#'){
                matriz[atual.second][atual.first-1] = 'o';
                fila.push({atual.first-1,atual.second});
            }
        }
        if(atual.first+1<larg && atual.second<prof-1){
            if(matriz[atual.second][atual.first+1] == '.' && matriz[atual.second+1][atual.first] == '#' ){
                matriz[atual.second][atual.first+1] = 'o';
                fila.push({atual.first+1,atual.second});
            }
        }
        if(atual.second+1<prof){
            if(matriz[atual.second+1][atual.first] == '.' ){
                matriz[atual.second+1][atual.first] = 'o';
                fila.push({atual.first,atual.second+1});
            }
        }
    }

    for(auto str : matriz){
        for(auto c : str){
            cout<<c;
        }
        cout<<"\n";
    }

    return 0;
}