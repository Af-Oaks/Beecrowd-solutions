#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main(){

    int entry=1;
    while(cin>>entry){
        if(entry==0)
            break;
        int remaining;
        vector<int>discarded,carts;

        for(int x=1;x<=entry;x++){
            carts.push_back(x);
        }

        int disc=1;
        while(carts.size()>1){
            vector<int> change = carts;
            for(int x=0;x<carts.size();x++){
                if(disc){
                    discarded.push_back(carts[x]);
                    disc=0;
                    change.erase(change.begin());
                }
                else{
                    disc=1;
                    change.push_back(carts[x]);
                    change.erase(change.begin());
                }
            }
            carts=change;
        }
        cout<<"Discarded cards: ";
        for(int x=0;x<discarded.size();x++){
            cout<< discarded[x];
            if(x<discarded.size()-1)
                cout<<", ";
        }
        cout<<"\n";
        cout<<"Remaining card: "<<carts[0]<<"\n";


    }

    return 0;
}