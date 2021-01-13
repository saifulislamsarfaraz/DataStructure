#include<stdio.h>
#include<time.h>

int isPrimeCount(int n)
{
    int i, count=0;

    for( i = 1 ; i<=n; i++)
    {
        if(n%i==0)
        {
            count++;
        }
    }
    if(count==2)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

int main()
{
    int i,N,count=0,flag;
    scanf("%d",&N);

    clock_t start = clock();

    for(i=2 ; i<=N; i++)
    {
    if (isPrimeCount(i)==1)
    {
        count++;
    }
    }

    printf("%d\n",count);
    clock_t end= clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %.5f",seconds);



}
