#include <bits/stdc++.h>

using namespace std;

int main(){

    char alfab[54]= {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

    int entr,troca;
    cin>>entr;
    string name;
    for(int x=0;x<entr;x++){
        cin>>name;
        cin>>troca;
        for(auto &a : name){
            a = alfab[26+ a -65 - troca];
        }
        cout<<name<<"\n";
    }

    return 0;
}