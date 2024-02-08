#include <bits/stdc++.h>

using namespace std;

int main(){

    string name;
    int entr;

    cin>>entr;
    getline(cin,name);

    while(entr--){
        getline(cin,name);
        multiset<char> rep;
        for(auto& a : name){
            if((int)a >= 65 && (int)a<=90 || (int)a>= 97 && (int)a<= 122){
                rep.insert(tolower(a));
            }
        }
        vector<char> resp;
        set<char>inseridos;
        int mais=0;
        for(int x =97 ;x<=122;x++){
            if(rep.count((char)x)>mais){
                resp.clear();
                inseridos.clear();
                resp.push_back((char)x);
                mais = rep.count((char)x);
                inseridos.insert((char)x);
            }
            if(rep.count((char)x)==mais && inseridos.count((char)x)==0 ){
                resp.push_back((char)x);
                inseridos.insert((char)x);
            }
        }
        for(auto a : resp){
            cout<<a;
        }
        cout<<"\n";
    }

    return 0;
}