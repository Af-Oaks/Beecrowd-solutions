#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main(){

    string name;
    int quant;
    cin>>quant;
    while(quant--){
        cin>>name;
        string resp;
        int a1=0,b1=0,troca=1;
        for(int x=1;x<name.size();x++){
            if(name[x]=='a' && troca){
                a1++;
            }else if(troca){
                x+=2;
                troca=0;
            }
            if(troca==0 & name[x] == 'a'){
                b1++;
            }
        }
        resp.push_back('k');
        for(int x=0;x<b1*a1;x++)
            resp.push_back('a');
        cout<<resp<<"\n";
    }
    return 0;
}