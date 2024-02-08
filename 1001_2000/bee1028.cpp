#include <bits/stdc++.h>

using namespace std;
#define int long long int

int32_t main(){

    int quant;
    cin>>quant;

    while(quant--){
        int a,b;
        cin>>a>>b;
        cout<<__gcd(a,b)<<"\n";
    }

    return 0;
}