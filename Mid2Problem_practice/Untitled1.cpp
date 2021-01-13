#include<bits/stdc++.h>
using namespace std;
int fact(int p, int n){
    if(p==0)
        return 1;
    return p*fact(p-1,n);
}
int main(){
    int n = 10;
    printf("%d\n",fact(n,n));
    return 0;
}
