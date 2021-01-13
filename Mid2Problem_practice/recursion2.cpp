#include<bits/stdc++.h>
using namespace std;
int fun(int n){
    if(n==0)
        return 0;
    else{
        fun(n-1);
        return printf("%d",n);
    }

}
int main(){
        int n = 5;
        fun(n);
}

