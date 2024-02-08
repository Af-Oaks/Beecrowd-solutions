#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main(){

    int entrada,carry;
    cin>>entrada;
    vector<int> vec_adj;
    vec_adj.resize(entrada+1);
    for(int x=1;x<=entrada;x++){
        cin>>carry;
        vec_adj[x] = carry;
    }
    set<int> distic;
    for(int x=1;x<=entrada;x++){
        int time=1,pos=x;
        while(x != vec_adj[pos]){
            pos = vec_adj[pos];
            time++;
        }
        distic.insert(time);
    }
    int maior=0,resp=1;
    for(auto a : distic){
        resp = lcm(resp,a);
    }
    cout<<resp<<"\n";


    return 0;
}