#include <bits/stdc++.h>

using namespace std;
#define int long long int

bool compara(pair<int,int> a ,pair<int,int> b){

    if(a.first > b.first)
        return true;
    else if(a.first < b.first)
        return false;
    else{
        if(a.second > b.second)
            return true;
        else 
            return false; 
    }
}

int32_t main(){

    int num_uepas,tam_lista,carry1,carry2;
    cin>>num_uepas>>tam_lista;
    vector<pair<int,int>> vec;
    set<int> values;
    for(int x=1;x<=num_uepas;x++)
        values.insert(x);
    for(int x=0;x<tam_lista;x++){
        cin>>carry1>>carry2;
        carry1>carry2 ? vec.push_back({carry1,carry2}) :vec.push_back({carry2,carry1});
    }
    sort(vec.begin(),vec.end(),compara);

    for(auto a : vec){
        if(values.count(a.first) ==1 && values.count(a.second) == 1)
            values.erase(a.second);
    }

    cout<<values.size()<<"\n";
    string name ="";
    int count =1;
    for(auto a :values){
        if(count < values.size()){
            cout<<a<<" "; count++;
        }
        else
            cout<<a;
    }
    cout<<"\n";

    return 0;
}