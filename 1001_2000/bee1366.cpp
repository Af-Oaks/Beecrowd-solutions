#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main(){

    int tam,carry1,carry2;

    while(cin>>tam){
        if(tam==0)
            break;
        vector<pair<int,int>> varetas;
        for(int x=0;x<tam;x++){
            cin>>carry1>>carry2;
            varetas.push_back({carry1,carry2/2});
        }
        int resp =0;
        for(auto a : varetas){
            resp+=a.second;
        }
        cout<<resp/2<<"\n";

    }

    return 0;
}