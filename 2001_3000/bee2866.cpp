#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main(){

    int entr;
    cin>>entr;
    while(entr--){
        string name;
        cin>>name;
        reverse(name.begin(),name.end());
        string resp;
        for(auto a : name){
            if(a>= 97 && a<= 122)
                resp.push_back(a);
        }
        cout<<resp<<"\n";
    }

    return 0;
}