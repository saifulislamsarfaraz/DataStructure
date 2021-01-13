#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int value;
    Node* next;

    Node(int v)
    {
        value = v;
        next = NULL;

    }

};
Node* head;
void addToEnd(int val){

   if(head==NULL){
   head = new Node(val);
   }else{
      Node* curr = head;
      while(curr->next!=NULL){
         curr = curr->next;
      }
      curr->next= new Node(val);
   }

}

void addToFirst(int val){
   Node* temp = new Node(val);
   temp->next = head;
   head = temp;
}

void searchForAddBefore_LL(int val,int insValue){
        Node *newNode,*preNode, *node;
        newNode = new Node(insValue);
        preNode = node = head;
        newNode->value = insValue;
        while (node->value!=val&&node!=NULL){
            preNode = node;
            node = node->next;
        }
        preNode->next = newNode;
        newNode->next = node;
}
void printLinkedList(){
        Node* curr = head;
        while(curr!=NULL){
         printf("%d\n",curr->value);
         curr = curr->next;
        }

}

int main(){
    addToFirst(12);
    addToFirst(23);
    addToFirst(35);
    addToFirst(57);
    searchForAddBefore_LL(23,34);
    printLinkedList();
    return 0;

}
