#include<bits/stdc++.h>
using namespace std;

int fact(int n){
    if(n>1)
        return n* fact(n-1);
    else
        return 1;
}
int nCr (int n, int r){
    return fact(n)/(fact(r)*fact(n-r));
}
int main(){

    long n,m;
    cin>>n;
    cin>>m;
    int ara[m];
    for(int i = 0; i < m; i++){
        cin>>ara[i];
    }
    sort(ara,ara + m);
    int cnt = 1;
    for(int i = 1; i < m; i++){
        if(ara[i]!=ara[i-1]){
            cnt++;
        }
    }
   // cout<<cnt<<endl;
    int a = 2*n;
    int b = n+1;
    int c = nCr(a,cnt);
    cout<<c/b;
    return 0;
}
