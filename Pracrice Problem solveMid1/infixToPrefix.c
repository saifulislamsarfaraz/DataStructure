#include<bits/stdc++.h>
using namespace std;

struct Stack{
    struct Node{
    int value;
    Node* next;
    Node(int v){
      value  = v;
      next = NULL;
    }
    };
    Node* head = NULL;
    int sz = 0;
    void push(int x){
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

    int top(){
       return head->value;
    }
    void printLinkedList(){
        Node* curr = head;
        while(curr!=NULL){
         printf("%d\n",curr->value);
        curr = curr->next;
        }

}
};
bool isBalanced(Stack s){



}
bool isOperand(char x){
        if(x == '+'||x == '-'||x == '*'||x == '/'){
            return false;
        }else{
            return true;
        }

}
int precedence(char x){
    if(x=='+'||x=='-')
        return 1;
    else if(x=='*'||x=='/')
        return 2;

    return 0;
}

int main(){


return 0;
}
