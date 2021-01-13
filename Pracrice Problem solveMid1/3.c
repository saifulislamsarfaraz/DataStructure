#include<bits/stdc++.h>
using namespace std;

int sumOfSeries(int n){

return (n * (n + 1) * (2*n+4))/12;


}

int main(){
int n = 10;
cout << sumOfSeries(n);

}
