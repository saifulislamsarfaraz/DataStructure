#include<bits/stdc++.h>
using namespace std;

struct Stack
{
    int ara[1005];
    int sz = 0;
    void push(int x)
    {
        ara[sz] = x;
        sz++;
    }

    void pop()
    {
        ara[sz] = 0;
        sz--;
    }

    int size()
    {

        return sz;
    }

    int top()
    {

        return ara[sz-1];

    }

};
void display(Stack s)
{
    if(s.size()>=0)
    {
        for(int i = s.size()-1; i >= 0; i--)
        {
            cout<<s.ara[i]<<endl;
        }
    }
}
int main()
{
    Stack s;
    s.push(23);
    s.push(32);
    s.push(20);
    display(s);
    return 0;
}
