#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[1005];
    int prefix_sum[1005];
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    prefix_sum[0] = arr[0];
    for(int i = 1; i < n; i++)
    {
        prefix_sum[i] = prefix_sum[i-1] + arr[i];
    }
    int q,l,r;
    cout<<"input q for quarry:"<<endl;
    cin>>q;
    for(int i = 0; i < q; i++)
    {
        cout<<"input l and r:"<<endl;
        cin>>l>>r;
        cout<<"This is sum from left to right :" <<prefix_sum[r-1] - prefix_sum[l-2]<<endl;
    }

    return 0;
}
