#include<bits/stdc++.h>
using namespace std;
int is_k(char p[],int n,int k){
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(p[i] == '1'){
                cnt++;
            }
        }
        if(cnt>=k){
            return 1;
        }else{
            return 0;
        }

}
void func(int n, char binary[],int p,int k){
    if(p==n){
        binary[p]=0;
       if(is_k(binary,n,k)==1){
        printf("%s\n",binary);
        return;
        }
        return;
    }

    binary[p] = '0';
    func(n,binary,p+1,k);
    binary[p] = '1';
    func(n,binary,p+1,k);
}

int main(){
    char binary[10];
    func(5,binary,0,3);
    return 0;
}
