#include<bits/stdc++.h>
using namespace std;
int isBalanced(string s, int len){
   if( len == 0)
            return 1;
        stack<char> st;
        for(int i=0; i<len; i++){
            if( s[i]=='(' ){
                st.push(')');
            }
            else if(s[i]==')'){
                if(st.empty() == 1){
                    return 0;
                }
                else{
                    st.pop();
                }
            }
        }
        if(st.empty())
            return 1;
        else
            return 0;
}

int main(){
    string str = {'(',')'};
    sort(str.begin(),str.end());
    do{
            if(isBalanced(str,str.length())==1){
            cout<<str<<endl;
            }
    }while(next_permutation(str.begin(),str.end()));
}

