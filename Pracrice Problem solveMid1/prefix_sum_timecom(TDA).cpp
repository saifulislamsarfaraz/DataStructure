#include<stdio.h>
int arr[1001][1001];
int main(){
    int n,m;

    scanf("%d%d",&n,&m);


    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            scanf("%d",&arr[i][j]);
        }
    }
    int pre_sum[1005][1005];
    for(int i = 0; i < n; i++){
        for(int j = 0; j<m; j++){
            pre_sum[i][j] = pre_sum[i-1][j]+pre_sum[i][j-1]-pre_sum[i-1][j-1]+arr[i][j];
        }
    }
    int b,q,t,l,r;
    printf("input q for quarry:");
    scanf("%d",&q);
    for(int i = 0; i < q; i++)
    {
        printf("input b and t and l and r:");
        scanf("%d%d%d%d",&t,&b,&r,&l);
        printf("This is sum from left to right :",pre_sum[b][r] - pre_sum[b][l-1] - pre_sum[t-1][r] + pre_sum[t-1][l-1]);
    }


    return 0;
}
