#include <bits/stdc++.h>

using namespace std;
#define int long long int

int max_quant(vector<int> &vec, int alvo)
{

    unordered_map<int, int> somas_anteriores;
 
    int resp = 0,soma_atual=0;
 
    for (int i = 0; i < vec.size(); i++) {
 
        soma_atual+= vec[i];

        if (soma_atual == alvo)
            resp++;

        if (somas_anteriores.find(soma_atual - alvo) != somas_anteriores.end())
            resp += (somas_anteriores[soma_atual - alvo]);
 
        somas_anteriores[soma_atual]++;
    }
 
    return resp;
}


int32_t main(){

    int quant,alvo;
    cin>>quant>>alvo;
    vector<int> vec;
    vec.resize(quant);
    for(int x=0;x<quant;x++){
        cin>>vec[x];

    }

    cout<<max_quant(vec,alvo)<<"\n";

    return 0;
}