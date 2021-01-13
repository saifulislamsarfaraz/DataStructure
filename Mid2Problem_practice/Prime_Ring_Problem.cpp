//print prime number of circle so that summation of two numbers are also prime
#include<bits/stdc++.h>
using namespace std;
int is_prime(int sum,int i = 2){
 if(sum<=2)
    return (sum==2)? 1 : 0;
    if(sum%i==0)
        return 0;
    if(i*i>sum)
        return 1;
    return is_prime(sum,i+1);


}
int prime(int arr[],int n){
      if(arr[0]!=1){
            return 0;
      }
      int flag = 0;
        for(int i = 0; i < n-1; i++){
                int sum_two = arr[i] + arr[i+1];
            if(is_prime(sum_two)==0){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            return 1;
        }
        return 0;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
            arr[i] = i+1;
    }
    do{
       if(prime(arr,n)!=0){
        for(int i = 0; i < n; i++){
            cout<<arr[i];
        }
        cout<<endl;
       }
    }while(next_permutation(arr,arr + n));
    return 0;
}
