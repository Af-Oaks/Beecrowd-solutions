#include <bits/stdc++.h>

using namespace std;
#define int long long int

int32_t main(){

    string names,indicados,amigo;
    getline(cin,names);
    getline(cin,indicados);
    getline(cin,amigo);
    
    if(amigo.compare("nao")==0){
        names.push_back(' ');
        names.append(indicados);
    }
    else{
        names.insert(names.find(amigo),indicados+" ");
    }
    
    cout<<names<<"\n";

    return 0;
}