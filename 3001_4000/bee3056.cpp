#include <bits/stdc++.h>

using namespace std;
#define int long long int

int32_t main(){

    int eventos;
    cin>>eventos;

    int start=2;
    for(int x=0;x<eventos;x++){
        start = start*2 -1;
    }    
    cout<<start*start<<"\n";

    return 0;
}