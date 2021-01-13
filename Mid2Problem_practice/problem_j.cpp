#include<bits/stdc++.h>
using namespace std;

int main(){

    long n,m;
    cin>>n;
    while(n>0){
    cin>>m;
    int ara[m];
    for(int i = 0; i < m; i++){
          cin>>ara[i];
        }
    int cnt = 0,cnt1 = 0;
    for(int i = 0; i < m; i++){
        if(ara[i]==i+1){
            cnt++;
        }
      }
      sort(ara,ara+m);
    for(int i = 0; i < m; i++){
        if(ara[i]==i+1){
            cnt1++;
        }
      }
      if(cnt==m && cnt1==m){
        cout<<"no"<<endl;
      }else{
          cout<<"yes"<<endl;
      }
      n--;
    }
    return 0;
}

