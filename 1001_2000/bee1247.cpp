#include <bits/stdc++.h>

using namespace std;

int main(){

    int dist,vf,vg;
  
    while(cin>>dist>>vf>>vg){


    if(vf>= vg){
        printf("N\n");
    }
    else{
        double time = 12.0/vf;
        double dist3 = sqrt(144.0 + dist*dist); 
        double time2 = dist3/vg;
        if(time<time2){
            printf("N\n");
        }
        else
            printf("S\n");
    }
    }


    return 0;
}