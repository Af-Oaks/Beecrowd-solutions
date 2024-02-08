#include <bits/stdc++.h>

using namespace std;
#define int long long int

int32_t main(){

    int area,n_altura,m_bases;

    while(cin>>area>>n_altura>>m_bases){
        if(area ==0 && n_altura==0 && m_bases==0){
            break;
        }
        int c1,c2,c3;
        cin>>c1>>c2>>c3;
        int resp = area*c1*abs(c3-c2)/( (n_altura+1)*(m_bases+1) );
        cout<<resp<<"\n";
    }

    return 0;
}