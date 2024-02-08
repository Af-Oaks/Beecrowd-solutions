#include <bits/stdc++.h>

using namespace std;
#define int long long int

int32_t main(){

    string op;
    int val1,val2;
    cin>>val1>>op>>val2;
    int carry,resp=0,count=1;
    carry =val1;
    val1=0;
    while(carry>0){
        if((carry%10)!=7){
            val1+= count*(carry%10);
        }
        carry/=10;
        count*=10;
    }
    carry =val2;count=1;
    val2=0;
    while(carry>0){
        if((carry%10)!=7){
            val2+= count*(carry%10);
        }
        carry/=10;
        count*=10;
    }
    // cout<<"val1 ="<<val1<<" val2="<<val2<<" \n";
    if(op[0]== '+'){
        carry = val1+val2;
    }
    else{
        carry = val1*val2;
    }
    count=1;
    while(carry>0){
        if((carry%10)!=7){
            resp+= count*(carry%10);
        }
        carry/=10;
        count*=10;
    }
    cout<<resp<<"\n";

    return 0;
}