#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    int r;
    cin>>str;
    cin>>r;

    //sort(str.begin(),str.end());
    vector<bool> v(str.length());
    fill(v.end() - r, v.end(), true);

    do{
        for(int i = 0; i < str.length(); ++i){
            if(v[i]){
                cout<<str[i+1];
            }
        }
        cout<<endl;
    }while (next_permutation(str.begin(),str.end()));
    //cout<<endl;
    return 0;


}
