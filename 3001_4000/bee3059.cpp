#include <bits/stdc++.h>

using namespace std;
#define int long long int

int32_t main(){

    int quant,lower,upper;
    cin>>quant>>lower>>upper;
    vector<int> vec;
    vec.resize(quant);
    for(int x=0;x<quant;x++){
        cin>>vec[x];
    }
    sort(vec.begin(),vec.end());
    int resp=0;
    for(int x=0;x<quant;x++){
        for(int y=x+1;y<quant;y++){
            if(vec[x] + vec[y] >= lower && vec[x] + vec[y] <= upper){
                resp++;
            }
            else if(vec[x] + vec[y] > upper){
                break;
            }
        }
    }
    cout<<resp<<"\n";


    return 0;
}