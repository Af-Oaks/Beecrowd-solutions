#include <iostream>
 
using namespace std;
 
int main() {
 
   long long unsigned int patinhos =0;
   
    while(scanf("%llu",&patinhos)){
        if(patinhos == (long long unsigned)-1)
            break;
        else if(patinhos == 0){
            printf("0\n");
        }
        else{
            patinhos--;
            printf("%llu\n",patinhos);
            }
   
   }
   
   
    return 0;
}