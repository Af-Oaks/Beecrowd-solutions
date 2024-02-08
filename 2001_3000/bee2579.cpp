#include <bits/stdc++.h>

using namespace std;
#define int long long int

int32_t main(){

    int linha,coluna,posx,posy;
    cin>>linha>>coluna>>posx>>posy;
    if((posx*coluna +posy)%2 ==0 )
        cout<<"Direita\n";
    else
        cout<<"Esquerda\n";

    return 0;
}