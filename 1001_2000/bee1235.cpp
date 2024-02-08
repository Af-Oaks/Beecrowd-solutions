#include <bits/stdc++.h>

using namespace std;


int main(){

    string name;
    int entra;
    cin>>entra;
    getline(cin,name);
    while(entra--){

        getline(cin,name);

        reverse(name.begin(),name.begin()+name.size()/2);
        reverse(name.begin()+name.size()/2,name.end());

        cout<<name<<"\n";

    }

    return 0;
}