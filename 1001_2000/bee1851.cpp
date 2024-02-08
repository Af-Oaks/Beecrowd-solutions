#include <bits/stdc++.h>

using namespace std;
#define int long long int

struct Comparator {
    bool operator()(tuple<int, int>& t1, tuple<int, int>& t2) {
         return std::get<1>(t1) > std::get<1>(t2);
     }
 };

int32_t main(){

    int carry1,carry2;
    int multa=0,restante=0;

    priority_queue<tuple<double,int,int>> fila;
    int time=0;
    while(cin>>carry1>>carry2){
        fila.push({(double)carry2/carry1,carry1,carry2});
        restante+=carry2;
        if(time==0){
            tuple<int,int,int> dragao = fila.top();
            fila.pop();
            // printf("priority =%lld drag = %lld\n",get<0>(dragao),get<2>(dragao));
            time = get<1>(dragao);
            restante-= get<2>(dragao);
        }
        time--;
        if(!fila.empty())
            multa+=restante;
        // printf("time=%lld | rest=%lld | multa=%lld \n",time,restante,multa);
    }
    // printf("troca\n");
    while(!fila.empty()){
        if(time==0){
            tuple<int,int,int> dragao = fila.top();
            fila.pop();
            if(fila.empty())
                break;
            time = get<1>(dragao);
            restante-= get<2>(dragao);
        }
        time--;
        multa+= restante;
        // printf("time=%lld | rest=%lld | multa=%lld \n",time,restante,multa);
    }
    cout<<multa<<endl;

    return 0;
}