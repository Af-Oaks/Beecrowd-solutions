#include <bits/stdc++.h>

using namespace std;
#define int long long int

int32_t main(){

    double a,b,c,r1,r2;
    cin>>a>>b>>c;

    if(pow(b,2) - (4*a*c) >=0 && a>0.0){
        r1 = ((-b + sqrt( pow(b,2) - (4*a*c) ))/(2*a)  );
        r2 = ((-b - sqrt( pow(b,2) - (4*a*c) ))/(2*a)  );

        printf("R1 = %0.5lf\nR2 = %0.5lf\n",r1,r2);
    }
    else{
        printf("Impossivel calcular\n");
    }


    return 0;
}