#include<bits/stdc++.h>
using namespace std;

struct Queue{
        struct Node{
            int value;
            Node* next;
            Node(){}
            Node(int v){
            value = v;
            next = NULL;
            }
        };
        int sz = 0;
        Node *head, *tail;
        Queue(){
        head = NULL;
        tail = NULL;
        }

        void push(int x){
        sz++;
        Node* temp = new Node(x);
        if(head==NULL){
            head = temp;
            tail = temp;
            return;

        }else{
        tail->next = temp;
        tail = tail->next;

        }
    }

    void pop(){
    sz--;
    Node* temp = head;
    head = head->next;
    if(head==NULL){
        tail = NULL;
    }
    free(temp);
    }
    int front(){

    return head -> value;
    }
    int size(){
    return sz;
    }
    void display(){
        Node* curr = head;
        while(head!=NULL){
            printf("%d\n",curr->value);
            curr = curr->next;
        }
    }

};
int main(){
    Queue Q;
    Q.push(6);
    Q.push(3);
    Q.push(5);
    Q.push(7);
    Q.pop();
   // Q.display();
    for(int i = 0; i < Q.size(); i++){
        printf("%d\n",Q.front());
    }
    return 0;

}
