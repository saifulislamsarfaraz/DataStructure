#include<bits/stdc++.h>
using namespace std;
int main(){
   int a[34][2];
   for(int i = 0; i < 34;i++){
    for(int j = 0; j < 2; j++){
        cin>>a[i][j];
    }
   }

    for(int k = 0; k < 34;k++){
    int sum = 0;
    for(int m = 0; m < 2; m++){
        sum  = sum + a[k][m];
    }
    printf("%d\n",sum);

   }
    return 0;
}
