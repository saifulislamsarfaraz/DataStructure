#include<bits/stdc++.h>
using namespace std;

struct Stack{
    struct Node{
    char value;
    Node* next;
    Node(char v){
      value  = v;
      next = NULL;
    }
    };
    Node* head = NULL;
    int sz = 0;
    void push(char x){
    Node* newNode = new Node(x);
    newNode -> next = head;
    head = newNode;
    sz++;
    }
    void pop(){
        if(sz==0){
            return;
        }
        Node* temp = head;
        head = head -> next;
        free(temp);
        sz--;
    }

    char top(){
       return head->value;
    }
    int size()
    {

        return sz;
    }
     void printLinkedList(){
        Node* curr = head;
        while(curr!=NULL){
        printf("%c\n",curr->value);
        curr = curr->next;
        }

     }
};

bool BracketsBalanced(Stack s)
{

    for(int i = 0; i < s.size();i++){
            if(s.top()=='(')
    }
}
int main()
{

    Stack s;
    s.push('(');
    s.push(')');
    s.push('(');
    s.push(')');
    s.printLinkedList();
    cout<<BracketsBalanced(s);

    return 0;
}
