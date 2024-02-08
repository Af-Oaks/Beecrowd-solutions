#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main(){

    string name;
    unordered_map<char,double> mapa = { {'W',1.0},{'H',0.5},{'Q',0.25},{'E',0.125},{'S',0.0625},{'T',0.03125},{'X',.015625}};
    while(cin>>name){
        if(name.compare("*") ==0)
            break;
        int resp=0;double time=0;
        for(auto a : name){
            if(a == '/'){
                if(time == 1.0){
                    resp++;
                }
                time=0.0;
            }
            else{
                time += mapa[a];
            }
        }
        cout<<resp<<"\n";
    }

    return 0;
}