#include <bits/stdc++.h>

using namespace std;
#define int long long int



int32_t main(){

    pair<int,int> casa,escola,p1,p2;
    double velocidade;

    while(cin>>casa.first>>casa.second>>escola.first>>escola.second>>velocidade){
        cin>>p1.first>>p1.second>>p2.first>>p2.second;

        //primeiro verificar se é possivel um caminho sem interferir com o terreno
        //caso interfirar verficar onde é a primeira interferencia | lado esq| baixo| cima
        //apos isso pegar a distancia da casa a um dos pontos esquerdos do terreno
        // logo a menor distancia é sempre
        //casa aos pontos esquerdos do terreno + lado do terreno + ponto direito a escola.
        
        double caminho1=0.0,caminho2=0.0;

        //caminho por cima
        caminho1 = sqrt( pow(p1.first - casa.first,2) + pow(p2.second - casa.second,2) ) 
                        +(p2.first - p1.first) +sqrt(pow(p2.first - escola.first,2) + pow(p2.second - escola.second,2) );
        caminho2 = sqrt( pow(p1.first - casa.first,2) + pow(p1.second - casa.second,2) ) 
                        +(p2.first - p1.first) +sqrt(pow(p2.first - escola.first,2) + pow(p1.second - escola.second,2) );

        // cout<<caminho1<<" "<<caminho2<<"\n";
        if(caminho1<= caminho2){
            printf("%0.1lf\n",caminho1/velocidade);
        }
        else{
            printf("%0.1lf\n",caminho2/velocidade);
        }

    }



    return 0;
}