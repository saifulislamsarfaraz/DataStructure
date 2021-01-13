#include<bits/stdc++.h>
using namespace std;

int digit_count(int digit){
  int count = 0;
  if(digit==0)
    return 0;
    else{
     count++;
     digit_count(digit/10);
    }

    return count;
}

int main(){
    int n = 505;
    cout<<digit_count(n)<<endl;

}
