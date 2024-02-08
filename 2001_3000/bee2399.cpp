#include <bits/stdc++.h>

using namespace std;
#define int long long int


int32_t main(){

    int quant,carry,next=0,last=-1;
    cin>>quant;
    vector<int>vec;
    while(quant--){
        cin>>carry;
        if(carry ==0){
            vec.push_back(0+next);
            next=0;
        }
        if(carry==1){
           vec.push_back(1+next);
           next=1;
           if(last>=0){
            vec[last] = vec[last] +1;
           }
        }
        last++;
    }
    // cout<<"----\n";
    for(auto a : vec)
        cout<<a<<"\n";

    return 0;
}