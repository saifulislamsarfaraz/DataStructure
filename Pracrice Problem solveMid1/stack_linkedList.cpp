#include<bits/stdc++.h>
using namespace std;
struct Stack{
        struct Node{
            int value;
            Node* next;
            Node(){}
            Node(int v){
            value = v;
            next = NULL;
            }
        };
        Node* head = NULL;
        int sz = 0;
        Stack(){
           head = NULL;
        }
        void push(int x){
            Node* temp = new Node(x);
            temp -> next = head;
            head = temp;
            sz++;
        }

        void pop(){
        if(sz==0){
            return;
        }
        Node* temp = head;
        head = head->next;
        free(temp);
        sz--;
        }

        int size(){
        return sz;
        }

        int top(){
        return head->value;
        }

        void display(){
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
    s.push(5);
    s.push(5);
    s.push(5);
    s.pop();
    s.display();

}
