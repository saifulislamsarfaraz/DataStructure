#include<bits/stdc++.h>
using namespace std;
//int is_envenish(int sub[],int subsize){
//            int evn = 0;
//            int odd = 0;
//            for(int i = 0; i < subsize; i++){
//                if(sub[i]%2==0){
//                    evn++;
//                }else{
//                   odd++;
//                }
//            }
//            if(evn>odd){
//                return 1;
//            }else{
//                return 0;
//            }
//
//}
int is_sum_maximum(int sum){
        int maxSum = 0;
        if()
}
int is_sum(int sub[], int subsize) {
            int sum = 0;
            for(int i = 0; i < subsize; i++){
                    sum +=sub[i];
            }
            return sum;
}
void func(int arr[],int arrsize,int sub[],int subsize,int index)
{
    if(is_sum(sub,subsize)){

        if()
    }
    if(is_envenish(sub,subsize)){
    for(int i =0; i<subsize; i++){
        printf("%d ",sub[i]);
        }
     printf("\n");
    }

    for(int i=index; i<arrsize; i++)
    {       //1
        sub[subsize]=arr[i];
        subsize++;
        func(arr,arrsize,sub,subsize,i+1);
        subsize--;
    }
    return;
}
int main()
{
    int arr[]={1,4,2};
    int sub[30];
    func(arr,3,sub,0,0);
}

