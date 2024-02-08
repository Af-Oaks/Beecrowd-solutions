#include <bits/stdc++.h>

using namespace std;
#define int long long int

bool IsPrime(int n)
{
    if (n == 2 || n == 3)
        return true;

    if (n <= 1 || n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}

int32_t main(){

    int num;

    while(cin>>num){

        if(IsPrime(num)){

            int teste = num;
            int valid=1;
            while(teste > 0){

                if( !IsPrime(teste%10) ){
                    valid=0;
                    break;
                }
                teste = teste/10;
                    
            }

            if(valid)
                cout<<"Super\n";
            else
                cout<<"Primo\n";

        }
        else{
            cout<<"Nada\n";
        }




    }


    return 0;
}

