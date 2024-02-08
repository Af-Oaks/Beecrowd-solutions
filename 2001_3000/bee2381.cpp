#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main(){

    int quant, pos;
    cin>>quant>>pos;
    string name;
    vector<string> alunos;
    while(quant--){
        cin>>name;
        alunos.push_back(name);
    }

    sort(alunos.begin(),alunos.end());
    cout<<alunos[pos-1]<<"\n";


    return 0;
}