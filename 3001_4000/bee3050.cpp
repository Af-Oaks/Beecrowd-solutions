    #include <bits/stdc++.h>

    using namespace std;
    #define int long long int

    int32_t main(){

        int quant,m_dist=0,pos_x=0,pos_y=0,dist_y=0;
        cin>>quant;
        vector<int> vec;
        vec.resize(quant);
        for(int x=0;x<quant;x++){
            cin>>vec[x];
            if(x + vec[x]> m_dist){
                m_dist = x +vec[x];
                pos_x = x;
            }
        }
        for(int x=0;x<pos_x;x++){
            if(pos_x -x + vec[x]>dist_y){
                dist_y= pos_x - x +vec[x];
                pos_y = x;
            }
            
        }
        for(int x=pos_x;x<quant;x++){
            if(x-pos_x + vec[x]>dist_y){
                dist_y= x - pos_x +vec[x];
                pos_y = x;
            }
        }

        cout<<vec[pos_x] + vec[pos_y] + abs(pos_x - pos_y)<<"\n";

        return 0;
    }