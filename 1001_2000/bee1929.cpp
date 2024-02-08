#include <bits/stdc++.h>

using namespace std; 

int main(){

    int a,b,c,d;

    cin>>a>>b>>c>>d;

    int possivel =0;

    if(a+b>c && a+c>b && c+b>a){
        possivel++;}
    if(a+d>c && a+c>d && c+d>a){
        possivel++;}
    if(d+b>c && d+c>b && c+b>d){
        possivel++;}
    if(d+b>a && d+a>b && a+b>d){
        possivel++;}
       
    if(possivel>=1){
        printf("S\n");
    }
    else
        printf("N\n");


    return 0;
}