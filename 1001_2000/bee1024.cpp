#include <bits/stdc++.h>

using namespace std;


int main(){

    string name;
    int entra;
    cin>>entra;
    getline(cin,name);
    while(entra--){

        getline(cin,name);

        for(auto& a : name){
            if( (int)a >= 65 && (int)a<=90 || (int)a>= 97 && (int)a<= 122){
                a+=3;
            }
        }
        reverse(name.begin(),name.end());

        for(int x = name.size()/2;x<name.size();x++){
            name[x]--;
        }

        cout<<name<<"\n";

    }

    return 0;
}