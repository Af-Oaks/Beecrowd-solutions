#include <bits/stdc++.h>

using namespace std;
#define int long long int

int32_t main(){

    int linha;
    double car1,car2;
    cin>>linha;
    vector<double> valores;
    valores.resize(linha);
    for(int x=0;x<linha;x++){
        cin>>car1>>car2;
        valores[x] = car1*1000.0/car2;
    }
    sort(valores.begin(),valores.end());
    printf("%0.2lf\n",valores[0]);

    return 0;
}