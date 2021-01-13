#include<bits/stdc++.h>
using namespace std;
int main(){
        int n;
        cin>>n;
        int arr[1005];
        for(int i = 0; i < n; i++ ){
            cin>>arr[i];
        }
        int prefix_sum[1005];
        prefix_sum[0] = arr[0];

        for(int i = 1; i < n; i++){

            prefix_sum[i] = prefix_sum[i-1]+ arr[i];
        }

        int q,l,r;
        cin>>q;
        for(int i = 0; i < q; i++){
            cin>>l>>r;
            cout<<"The sum is :"<<prefix_sum[r-1] - prefixsum[l-2];

        }



}
