#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main(){

    int quant;
    cin>>quant;

    while(quant--){
        string a,b;
        cin>>a>>b;
        if(b.size()> a.size()){
            printf("nao encaixa\n");
            continue;
        }
        else{
            string test= a.substr(a.size()-b.size(),a.size());
            int resp= b.compare(test);
            if(resp ==0){
                printf("encaixa\n");
            }
            else{
                printf("nao encaixa\n");
            }
        }
    }

    return 0;
}