#include<bits/stdc++.h>
using namespace std;


struct Queue
{
    struct Node
    {
        int value;
        Node* next;
        Node() {}
        Node(int x)
        {
            value = x;
            next = NULL;
        }
    };
    int sz = 0;
    Node* head;
    Node* tail;

    Queue()
    {
        head = NULL;
        tail = NULL;
    }
    void push(int x)
    {
        sz++;
        Node* temp = new Node(x);
        if(head==NULL)
        {
            head = temp;
            tail = temp;
            return;
        }
        else
        {
            tail->next = temp;
            tail = tail->next;
        }

    }
    void pop()
    {
        if(head == NULL)
        {
            printf("Nothing here");
            return;
        }
        sz--;
        Node* temp = head;
        head = head->next;
        if(head==NULL)
        {
            temp = NULL;
        }
        free(temp);


    }

    int front()
    {
        return head->value;
    }
    int size()
    {
        return sz;
    }

    void display(){
        if(head==NULL){
            return;
        }
        while(head!=NULL){
            printf("%d\n",head->value);
            head = head->next;
        }

    }

};



int main()
{
    Queue s;
//    s.push(1);
//    s.push(2);
//    s.push(3);
//    s.push(4);
    s.pop();
    s.display();


return 0;
}
