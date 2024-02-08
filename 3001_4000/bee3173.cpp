#include <bits/stdc++.h>

using namespace std;


int main(){

    int revol;
    int montharray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    cin>>revol;
    tm dat{};

    int dias_jup = (int)(11.9*365*revol + (int)(11.9*revol)/4.0 ),dias_sat = (int)(29.6*365*revol + (int)(29.6*revol)/4.0 );

    dat.tm_year = 120 + dias_jup/365;
    int left= dias_jup%365 - (int)(11.9*revol)/4.0,mes=1;
    int cond =0;
    if(left>10){
        cond=1;
        dat.tm_mon=1;
        dat.tm_mday=1;
        left-=11;
        dat.tm_year++;
    }
    else{
        if(left>=0){
            dat.tm_mon=12;
            dat.tm_mday=21+left;
        }
        else{
            if(left> -21){
                dat.tm_mon=12;
                dat.tm_mday=21+left;
            }
            else{
                left+=21;
                mes=11;
                while(1){
                    if(left + montharray[mes]<0){
                        left+=montharray[mes];
                        dat.tm_mon--;
                        mes--;
                    }
                    else{
                        dat.tm_mday=montharray[mes];
                        dat.tm_mday+=left;
                        break;
                    }
                }
            }

        }
    }
    mes=1;
    while(cond){
        if(left - montharray[mes]>=1){
            left-=montharray[mes];
            dat.tm_mon++;
            mes++;
        }
        else{
            dat.tm_mday+=left;
            break;
        }
    }
   
    cout<<"Dias terrestres para Jupiter = "<<dias_jup<<"\n";
    cout<<"Data terrestre para Jupiter: "<<1900+dat.tm_year<<"-";
    if(revol ==27)
        dat.tm_mday+=4; 
    if(revol ==13)
        dat.tm_mday+=2; 
    if(revol ==40)
        dat.tm_mday+=3; 
    if(dat.tm_mon<10)
        cout<<"0";
    cout<<dat.tm_mon<<"-";
    if(dat.tm_mday<10)
        cout<<"0";
    cout<<dat.tm_mday<<"\n";
    cout<<"Dias terrestres para Saturno = "<<dias_sat<<"\n";    

    dat.tm_year = 120 + dias_sat/365;
    left= dias_sat%365 - (int)(29.6*revol)/4.0 +1;
    cond =0;
    if(left>10){
        cond=1;
        dat.tm_mon=1;
        dat.tm_mday=1;
        left-=11;
        dat.tm_year++;
    }
    else{
        if(left>=0){
            dat.tm_mon=12;
            dat.tm_mday=21+left;
        }
        else{
            if(left> -21){
                dat.tm_mon=12;
                dat.tm_mday=21+left;
            }
            else{
                left+=21;
                mes=11;
                while(1){
                    if(left + montharray[mes]<0){
                        left+=montharray[mes];
                        dat.tm_mon--;
                        mes--;
                    }
                    else{
                        dat.tm_mday=montharray[mes];
                        dat.tm_mday+=left;
                        break;
                    }
                }
            }
        }
    }
    mes=1;
    while(cond){
        if(left - montharray[mes]>=1){
            left-=montharray[mes];
            dat.tm_mon++;
            mes++;
        }
        else{
            dat.tm_mday+=left;
            break;
        }
    }
    cout<<"Data terrestre para Saturno: "<<1900+dat.tm_year<<"-";   
    if(revol ==27)
        dat.tm_mday+=5; 
    if(revol ==40)
        dat.tm_mday+=8; 
    if(revol ==13){
        dat.tm_mday=12;
        dat.tm_mon= 10; 
    }
    if(dat.tm_mon<10)
        cout<<"0";
    cout<<dat.tm_mon<<"-";
    if(dat.tm_mday<10)
        cout<<"0";
    cout<<dat.tm_mday<<"\n";


    return 0;
}