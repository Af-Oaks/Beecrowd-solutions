#include <bits/stdc++.h>

using namespace std;
#define int long long int

int32_t main(){

    double a,b,c,d,e;
    cin>>a>>b>>c>>d;
    double media = (2*a+3*b+4*c+d)/10.0;
    printf("Media: %0.1lf\n",media);

    if(media<5.0){
        printf("Aluno reprovado.\n");
    }
    else if( media>=6.0){
        printf("Aluno aprovado.\n");
    }
    else{
        printf("Aluno em exame.\n");
        cin>>e;
        printf("Nota do exame: %0.1lf\n",e);
        if((e+media)/2.0>=5.0){
            printf("Aluno aprovado.\n");
        }
        else{
            printf("Aluno aprovado.\n");
        }
        printf("Media final: %0.1lf\n",(e+media)/2.0);
    }


    return 0;
}