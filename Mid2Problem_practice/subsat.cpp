#include<stdio.h>

int is_envenish(int sub[],int subsize){
            int evn = 0;
            int odd = 0;
            for(int i = 0; i < subsize; i++){
                if(sub[i]%2==0){
                    evn++;
                }else{
                   odd++;
                }
            }
            if(evn>odd){
                return 1;
            }else{
                return 0;
            }

}
void func(int arr[],int arrsize,int sub[],int subsize,int index)
{

    //if(is_envenish(sub,subsize)){
    for(int i =0; i<subsize; i++){
        printf("%d ",sub[i]);
        }
     printf("\n");
    //}
            //1
    for(int i=index; i<arrsize; i++)
    {
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
