#include<bits/stdc++.h>
using namespace std;

void toh(int n,int src,int spare, int des){
        if(n==0)
            return;
        toh(n-1,src,des,spare);
        printf("Move from %d to %d \n",src,des);
        toh(n-1,spare,src,des);
}
int main(){
    toh(4,1,2,3);
    return 0;
}
