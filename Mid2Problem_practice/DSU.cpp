#include<bits/stdc++.h?
using namespace std;
int par[1005];
void int(){
    for(int i = 1; i <= n; i++){
        par[i] = -1;
    }
}
int findRoot(int u){
    while (par[u]!=-1){
        u = par[u];
    }
    return u;
}

int marge(int a, int b){
   a = findRoot(a);
   b = findRoot(b);
   par[b] = a;
}

void update( int a , int b){
    marge(a,b);
}
int query(int x){
    return (findRoot(x));

}
