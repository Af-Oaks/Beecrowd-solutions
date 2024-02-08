#include <bits/stdc++.h>

using namespace std;
#define int long long int


int32_t main(){

    string num1,num2;

    while(cin>>num1>>num2){
        if(num1.compare("0") ==0 && num2.compare("0")==0)
            break;
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        int menor,maior;
        if(num1.size()>num2.size()){
            maior=1;
            menor = num2.size();
        }
        else{
            maior=2;
            menor = num1.size();    
        }
        int carry =0,resp=0,carry2=0;
        for(int x=0;x<menor;x++){
            carry2 = (int)num1[x] -48 +(int)num2[x] -48 +carry ;
            if(carry2>=10){
                carry=carry2/10;
                resp++;
            }
            else{
                carry=0;
            }
        }
        if(maior ==1){
            for(int x = menor ;x<num1.size();x++){
                carry2 =  (int)num1[x] -48 +carry; 
                if(carry2 >=10){
                    carry = carry2/10;
                    resp++;
                }
                else{
                    carry=0;
                }
            }
        }
        else{
            for(int x = menor ;x<num2.size();x++){
                carry2 =  (int)num2[x] -48 +carry; 
                if(carry2 >=10){
                    carry = carry2/10;
                    resp++;
                }
                else{
                    carry=0;
                }
            }
        }

        if(resp ==0)
            cout<<"No carry operation.\n";
        else if(resp ==1){
            cout<<resp<<" carry operation.\n";
            }
        else
            cout<<resp<<" carry operations.\n";


    }


    return 0;
}