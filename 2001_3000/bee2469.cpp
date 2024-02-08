#include <bits/stdc++.h>

using namespace std;

/*
    apenas criar um multiset e jogar os numeros la dentro
    percorrer e retirar o de maior elemento!
*/

int main(){

    int tam,carry;

    cin>>tam;
    
    multiset<int> num;
    while(tam--){
        cin>>carry;
        num.insert(carry);
    }
    int maior=0;

    for(int a : num){
        if(num.count(a)>=num.count(maior)){
            if(a>maior)
                maior =a;
            }
    }

    printf("%d\n",maior);

    return 0;
}