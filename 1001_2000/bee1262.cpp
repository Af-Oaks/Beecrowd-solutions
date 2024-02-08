#include <bits/stdc++.h>

using namespace std;

int main(){

    string name;
    int numb;
    while(cin>>name){
        cin>>numb;
        int count =1;
        int resp =0,last=1;
        //RWWRRR
        // cout<<"("<<name<<")- ";
        for(int x=0;x<name.size();x++){
            // printf("%c",name[x]);
            if(name[x] == 'W'){
                resp++;
                // printf("|");
                count=1;
                last=1;
                if(x>=1){
                    if( name[x-1] == 'R'){
                        resp++;
                        // printf("|");
                    }
                }
            }
            else{
                if(count<=numb){
                    count++;
                    last=0;
                }
                else{
                    resp++;
                    // printf("|");
                    count =2;
                    last=0;
                }
            }
        }
        if(last==0)
            resp++;
        printf("%d\n",resp);
    }

    return 0;
}