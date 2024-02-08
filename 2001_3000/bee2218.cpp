#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main(){

    ll entry,carry;
    cin>>entry;

    for(int x=0;x<entry;x++){
        cin>>carry;
        cout<<(carry*(carry+1)/2 +1)<<"\n";
    }

    return 0;
}