#include<bits/stdc++.h>
using namespace std;
int fun(int n){
    if(n==0)
        return 0;
    else{
        printf("%d",n);
        return fun(n-1);
    }

}
int main(){
        int n =5;
        fun(n);


}
