#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,m;

    while(cin>>n>>m){
        if(n==0 & m==0){
            break;
        }
        vector<string> matriz;
        string name;
        for(int x=0;x<n;x++){
            cin>>name;
            matriz.push_back(name);
        }
        int new_n,new_m;
        cin>>new_n>>new_m;

        vector<string> new_mat;
        int multi_lin = new_n/n;
        int multi_col = new_m/m;
        for(int x=0;x<n;x++){
            string carry;
            for(auto a : matriz[x]){
                for(int x=0;x<multi_col;x++)
                    carry.push_back(a);
            }
            for(int x=0;x<multi_lin;x++)
                new_mat.push_back(carry);
        }

        for(auto a : new_mat)
            cout<<a<<"\n";
        cout<<"\n";
    }


    return 0;
}