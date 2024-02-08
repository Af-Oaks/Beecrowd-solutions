#include <bits/stdc++.h>

using namespace std;
// #define int long long int

int t  [400040];
int seq[100010];

void build(int *a, int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] * t[v*2+1];
    }
}

void update(int v, int tl, int tr, int pos, int new_val) {

    if (tl == tr) {
        t[v] = new_val;
    }
    else{
        int tm = (tl + tr) / 2;
        (pos <= tm) ? update(v*2, tl, tm, pos, new_val) : update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] * t[v*2+1];
    }
}

int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 1;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm)) * sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}



int32_t main(){

    int tam_seq,quant_comands,carry;
    string letra; int num1,num2;

    while(cin>>tam_seq>>quant_comands){
        for(int x=0;x<tam_seq;x++){
            cin>>carry;
            seq[x] = (carry > 0? 1 : (carry < 0 ? -1 : 0)) ;
        }

        build(seq,1,0,tam_seq-1);
        // string sresp;
        for(int x=0;x<quant_comands;x++){
            cin>>letra>>num1>>num2;
            
            if(letra[0] == 'C'){
                update(1,0,tam_seq-1,num1-1,(num2 > 0? 1 : (num2 < 0 ? -1 : 0)));    
            }
            else{
                int resp=sum(1,0,tam_seq-1,num1-1,num2-1);
                // sresp.push_back((resp >0 ) ? '+' : ( (resp<0) ? '-' : '0') );
                cout<< ( (resp >0 ) ? "+" : ( (resp<0) ? "-" : "0") );
            }
        }
        std::cout<<"\n";
    }


    return 0;
}