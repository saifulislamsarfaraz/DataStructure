#include<bits/stdc++.h>
using namespace std;
void f(int n, int curr[], int num, int rem, int k){
        if(rem==0){
            for(int i = 0; i < k; i++){
                printf("%d\n",curr[i]);
            }
            return;
        }
        if(num>n){
            return;
        }
        f(n,curr,num+1,rem,k);
        curr[k-rem] = num;
        f(n,curr,num+1,rem-1,k);
}

int main(){
    int curr[3];
    f(4,curr,3,3,3);


}
