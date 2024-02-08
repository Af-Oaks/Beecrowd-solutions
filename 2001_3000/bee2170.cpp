#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main (){

    double val1,val2;
    
    int start=1;
    while(cin>>val1>>val2){
        printf("Projeto %d:\nPercentual dos juros da aplicacao: %0.2lf %c\n",start,((val2/val1)-1.0 )*100,37);
        start++;
        printf("\n");
    }

    return 0;
}