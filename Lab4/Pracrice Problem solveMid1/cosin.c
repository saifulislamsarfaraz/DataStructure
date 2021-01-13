#include<stdio.h>
int main(){
        int n;
        scanf("%d",&n);
        if(n==1){
           printf("%d%d%d\n",1,1,1);
           printf("%d%d%d\n",1,2,2);
        }
        else{
        for(int i = 2; i <= n; i++){
            for(int j = 1; j <=2; j++){

                            if(j==1)
                        printf("%d%d%d\n",i,i*i,i*i*i);
                            else
                             printf("%d%d%d\n",i,i*i+1,i*i*i+1);


            }
        }
        }

}
