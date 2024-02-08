#include <bits/stdc++.h>

using namespace std;
#define int long long int

int32_t main(){

    double valor,taxa;
    int meses;

    while(cin>>valor>>taxa>>meses){

        double comp_valor,simp_valor;

        comp_valor= valor*pow(1.0+taxa,meses);
        simp_valor= valor*(taxa)*meses + valor; 



        printf("DIFERENCA DE VALOR =  %0.2lf\n",abs(comp_valor - simp_valor));
        printf("JUROS SIMPLES = %0.2lf\n",simp_valor - valor);
        printf("JUROS COMPOSTO = %0.2lf\n",comp_valor - valor);

    }


    return 0;
}