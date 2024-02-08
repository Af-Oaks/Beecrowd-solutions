#include <bits/stdc++.h>

using namespace std;
#define int long long int

int32_t main(){

    int quant,perg,carry;
    int numero_perg=1;
    while(cin>>quant>>perg){
        if(quant==0 && perg ==0)
            break;
        vector<int> vec;
        unordered_map<int,int> posi;
        for(int x=0;x<quant;x++){
            cin>>carry;
            vec.push_back(carry);
        }
        sort(vec.begin(),vec.end());
        int count=1;
        for(auto a : vec){
            if(posi[a]==0)
                posi[a]=(count);
            count++;
        }
        printf("CASE# %lld:\n",numero_perg);
        for(int x=0;x<perg;x++){
            cin>>carry;
            if(posi[carry]==0)
                printf("%lld not found\n",carry);
            else
                printf("%lld found at %lld\n",carry,posi[carry]);
        }
        numero_perg++;
    }

    return 0;
}