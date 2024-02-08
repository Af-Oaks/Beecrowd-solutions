#include <bits/stdc++.h>

using namespace std;
#define int long long int

int smallestpositive(vector<int> arr, int n) {
    int res = 1; // Initialize result
  
   sort(arr.begin(), arr.end());
   // Traverse the array and increment 'res' if arr[i] is
   // smaller than or equal to 'res'.
   for (int i = 0; i < n && arr[i] <= res; i++)
       res = res + arr[i];
  
   return res;
}

int32_t main(){

    int quant,atual;
    cin>>quant;

    while(quant--){
        cin>>atual;
        vector<int> vec;
        vec.resize(atual);
        for(int x=0;x<atual;x++)
            cin>>vec[x];
        
        cout<<smallestpositive(vec,atual)<<"\n";
    }


    return 0;
}