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
void deleteNode(int v){
    if(head->value==v){
        Node* temp = head;
        head = head -> next;
        free(temp);
    }
    Node* curr = head;
    while (curr!=NULL&& curr->value!=v){
        curr = curr->next;
    }
    if(curr==NULL){
        return;
    }
    Node* previous = head;
    while (previous->next!=curr){
        previous = previous->next;
    }
    previous->next = curr->next;
    free(curr);

}
void addToFirst(int val){
   Node* temp = new Node(val);
   temp->next = head;
   head = temp;
}

void searchForAddAfter_LL(int val,int insValue){
        Node *newNode,*preNode, *node;//টু পয়েন্টার ইউজ করতে হবে তাই দুইটা পয়েন্টার আর  এক্সাট্রা পয়েন্টারে ভেলুকে রাখার জন্য নিয়ে নিলাম
        newNode = new Node(insValue);//নিঊনোডের জায়গা দখল করলাম
        preNode = node = head;//প্রথমে হেডকে ধরে নোড কে আগাবো নোডের পিছনে প্রিনোড থাকবে যাতে এই দুইয়ের মাঝে ভেলু বসাতে পারি অর্থাত প্রিনোডের সমান ভালু হলেই থামবো
        newNode->value = insValue;// জাকে নিউ নোডে রাখতে চাই তাকে রেখে দিলাম
        while (preNode->value!=val&&node!=NULL){
            preNode = node;//প্রিনোড পিছনে থাকছে
            node = node->next;//নোড এক ঘর করে আগাচ্ছে //সমান হলেই লুপ থেকে বের হয়ে যাবে
        }
        preNode->next = newNode;//আসলো প্রিনোডের সাথে নেওনোডকে কানেক্ট করে দিলাম
        newNode->next = node;//নিউনোডের সাথে নোডের কানেক্ট করে দিলাম
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
    searchForAddAfter_LL(35,34);
    deleteNode(57);
    printLinkedList();
    return 0;

}
