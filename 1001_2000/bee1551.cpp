#include <bits/stdc++.h>

using namespace std;

int main(){

    int quant; string name;
    cin>>quant;
    getline(cin,name);
    while(quant--){

        getline(cin,name);
        set<char> rep;
        for(auto& a : name){
            if((int)a >= 65 && (int)a<=90 || (int)a>= 97 && (int)a<= 122){
                rep.insert(tolower(a));
            }
        }
        if(rep.size()<13)
            printf("frase mal elaborada\n");
        else if(rep.size()<26)
            printf("frase quase completa\n");
        else
            printf("frase completa\n");
    }

    return 0;
}