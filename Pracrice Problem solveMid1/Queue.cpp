#include<bits/stdc++.h>
using namespace std;

struct Stack{
        int lim = 50;
        int ara[lim];
        int f,e,sz;
        Stack(){
        f = 0;
        e = -1;
        sz = 0;

        }

        void push(int x){
            e++;
            if(e==lim){
                e = 0;
            }
            ara[e] = x;
            sz++;
        }

        void pop(){
            f++;
        if(f==lim){
            f = 0;
            }
            sz--;
        }

        void front(){
            return ara[f];
        }
        int size(){
            return sz;
        }
}
