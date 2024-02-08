#include <bits/stdc++.h>

using namespace std;
#define int long long int

int32_t main(){

    int a,b,total = 70*80;
    cin>>a>>b;
    int area = (a+b)*35;

    if(area >total){
        cout<<"1\n";
    }
    else if(area < total){
        cout<<"2\n";
    }
    else
        cout<<"0\n";




    return 0;
}