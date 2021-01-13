#include<bits/stdc++.h>
using namespace std;


int fibonacci_series(int n){
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    return fibonacci_series(n-1) + fibonacci_series(n-2);
}

int main(){

        int n;
        cin>>n;
        for(int i = 0; i < n; i++){
            cout<<fibonacci_series(i)<<endl;
        }
        return 0;
}

