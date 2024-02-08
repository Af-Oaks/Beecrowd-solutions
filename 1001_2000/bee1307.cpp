#include <bits/stdc++.h>

using namespace std;

int mdc(int a,int b){
    if(a%b==0)
        return b;
    else{
        return mdc(b,a%b);
    }
}

int main(){
    int quant;
    string name,love;
    cin>>quant;
    for(int x=1;x<=quant;x++){
        int resp=0,lov=0,entr=0;
        cin>>name>>love;
        reverse(name.begin(),name.end());
        reverse(love.begin(),love.end());
        int pot=0;
        for(auto a: name){
            if(a == '1'){
                entr += pow(2,pot);
            }
            pot++;
        }
        pot=0;
        for(auto a: love){
            if(a == '1'){
                lov += pow(2,pot);
            }
            pot++;
        }

        if(mdc(entr,lov) >1){
            printf("Pair #%d: All you need is love!\n",x);
        }
        else{
            printf("Pair #%d: Love is not all you need!\n",x);
        }
    }


    return 0;
}