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
int main(){
    Stack s;
    s.push(5);
    s.push(6);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(1);
    s.printLinkedList();
}
