#include <bits/stdc++.h>

using namespace std;

int conv(char a){
    return (int)a -48;
}
int tonumber(vector<string>mat, int pos){

    return 1000*conv(mat[0][pos]) +100*conv(mat[1][pos])+10*conv(mat[2][pos]) +conv(mat[3][pos]);
}

int main(){

    vector<string> mat;
    string name;
    for(int x=0;x<4;x++){
        cin>>name;
        mat.push_back(name);
    }
    string resp;
    
    for(int x=1;x<name.length()-1;x++){
        int carry=(( tonumber(mat,0)*(tonumber(mat,x)) + tonumber(mat,name.length()-1) )%257);
        // printf("carry=%d = (%d *%d + %d )\n",carry,tonumber(mat,0),tonumber(mat,x),tonumber(mat,name.length()-1));
        resp.push_back((char)carry);
    }
    cout<<resp<<"\n";

    return 0;
}