#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main(){

    ll quant,carry; string name;
    cin>>quant;
    while(quant--){
        cin>>name>>carry;
        carry =carry%(ll)pow(2.0,(int)name.size());
        ll extra =0;
        for(int x=0;x<name.size();x++){
            if(name[x]=='O'){
                extra+= (ll)pow(2,x);
            }
        }
        carry = (extra + carry)%(ll)pow(2.0,(int)name.size());
        vector<int> num;
        while(carry){
            num.push_back(carry%2);
            carry = carry/2;
        }
        string resp;
        for(int x =0;x<name.size();x++)
            resp.push_back('X');

        for(int x =num.size()-1;x>=0;x--){
            if(num[x]==1)
                resp[x]= 'O';
        }

        cout<<resp<<"\n";
    }
    return 0;
}