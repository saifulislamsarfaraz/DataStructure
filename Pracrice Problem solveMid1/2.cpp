#include<bits/stdc++.h>
#include<time.h>
using namespace std;


int sumOfSeries(int n)
{
    int sum = 0;
    for(int i = 1; i <=n; i++)
    {
        for(int j = 1; j<=i; j++)
        {
            sum+=j;
        }
    }

    return sum;
}



//int sumOfSeries(int n){
//        return (n * (n + 1) * (2 * n + 4));
//
//    }
int main()
{
    clock_t start = clock();
    int n = 100000000000;
    cout<< sumOfSeries(n);

    clock_t end= clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;
    cout<<endl;
    cout<<"Time taken: "<<seconds<<endl;
}
