#include <bits/stdc++.h>

using namespace std;

int mdc(int a,int b){
    if(a%b == 0)
        return b;
    else
        return mdc(b, a%b);
}

int main(){

    string name;
    int bingos =0,palavras=0,count=0;
    set<string> diff;
    while(cin>>name){

        if(name.compare("BULLSHIT")==0){
            bingos++;
            palavras+=count;
            count=0;
            diff.clear();
        }
        else if((name[0]>= 65 && name[0]<=90) || (name[0]>= 97 && name[0]<= 122)){
            int doub =1;
             for (auto& x : name) { 
                x = tolower(x); 
                if(x <65 || (x>90 && x<97) || x>122 ){
                    doub++;
                }
            } 
            if(diff.count(name)==0){
                count+= doub;
                diff.insert(name);
            }
        }
    }
    int mm = mdc(bingos,palavras);
    //printf("bing=%d | pal=%d | mm=%d\n",bingos,palavras,mm);
    printf("%d / %d \n",palavras/mm,bingos/mm);
    return 0;
}