#include <bits/stdc++.h>

using namespace std;
#define int long long int

bool compara(tuple<int,int,string> a ,tuple<int,int,string> b){

    if(get<0>(a) < get<0>(b)){
        return true;
    }
    else if(get<0>(a) > get<0>(b)){
        return false;
    }
    else{
        if(get<1>(a) < get<1>(b)){
            return true;
        }
        else if(get<1>(a) > get<1>(b)){
            return false;
        }
        else{
            if(get<2>(a).compare(get<2>(b)) < 0){
                return true;
            }
            else if(get<2>(a).compare(get<2>(b)) ==0) 
                return true;
            else 
                return false;
        }
    }

}

int32_t main(){

    int quant,carry;
    while(cin>>quant){
        vector<tuple<int,int,string>> vec;
        string name,regiao;
        while(quant--){
            cin>>name>>regiao>>carry;
            vec.push_back({carry,(int)regiao[0]-48,name});
        }
        sort(vec.begin(),vec.end(),compara);
        // cout<<"----\n";
        for(auto a : vec)
            cout<<get<2>(a)<<"\n";

    }

    return 0;
}