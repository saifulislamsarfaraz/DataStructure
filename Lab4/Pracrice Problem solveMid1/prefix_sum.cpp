#include<bits/stdc++.h>
int main()
{
    int arr[1005];
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);

    }

    int q, l, r ,sum = 0;
    scanf("%d",&q);

    for(int i = 0; i < q; i++)
    {
        scanf("%d %d",&l,&r);
        sum = 0;
        for(int j = l; j <= r; j++)
        {
            sum+=arr[j];
        }
        printf("%d",sum);
    }

}
