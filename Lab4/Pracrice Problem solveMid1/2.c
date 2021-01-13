#include<bits/stdc++.h>
using namespace std;
int sumOfSeries(int n){
int sum = 0;
for(int i = 1; i <= n; i++){
    for(int j = 1; j<= i; i++){
        sum+=j;
    }
}
return sum;
}
int main{
  n = 10;
  cout<<sumOfSeries(n);
  return 0;

}
