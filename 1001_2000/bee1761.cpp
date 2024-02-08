#include <bits/stdc++.h>

using namespace std;

double converter(double degree)
{
    double pi = 3.141592654;
    return (degree * (pi / 180));
}

int main(){

    double a,b,c;

    while(cin>>a>>b>>c){
        double resp=0,altura;

        altura = b*tan(converter(a)) + c;

        printf("%0.2lf\n",altura*5);
    }

    return 0;
}