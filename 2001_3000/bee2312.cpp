#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

bool sorta(tuple<int,int,int,string> a ,tuple<int,int,int,string> b){

    if(get<0>(a) > get<0>(b)){
        return true;
    }
    else if(get<0>(a) < get<0>(b) ){
        return false;

    }
    else{
        if(get<1>(a) > get<1>(b)){
            return true;
        }
        else if(get<1>(a) < get<1>(b) ){
            return false;

        }
        else{
            if(get<2>(a) > get<2>(b)){
                return true;
            }
            else if(get<2>(a) < get<2>(b) ){
                return false;

            }
            else{
                if(get<3>(a)[0] > get<3>(b)[0]){
                    return false;
                }
                else if(get<3>(a)[0] < get<3>(b)[0] ){
                    return true;
                }
                else{
                    return true;
                }
            }
        }

    }



}


int main(){

    string name;
    vector<tuple<int,int,int,string>> paises;
    int quant,car1,car2,car3;
    cin>>quant;

    while(quant--){
        cin>>name>>car1>>car2>>car3;
        paises.push_back({car1,car2,car3,name});
    }
    sort(paises.begin(),paises.end(),sorta);

    // cout<<"-------------\n";
    for(auto a: paises){
        cout<<get<3>(a)<<" "<<get<0>(a)<<" "<<get<1>(a)<<" "<<get<2>(a)<<"\n";
    }

    return 0; 
}