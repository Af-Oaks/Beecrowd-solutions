#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;


int main(){

    int quant,pessoas;
    cin>>quant;

    while(quant--){
        cin>>pessoas; string name;
        set<string> linguas;
        for(int x=0;x<pessoas;x++){
            cin>>name;
            linguas.insert(name);
        }
        if(linguas.size()>1)
            cout<<"ingles\n";
        else{
            for(auto a : linguas)
                cout<<a<<"\n";
        }
    }

    return 0;
}