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

//void inti(int val){
//        head = new Node(val);
//}

void addToEnd(int val)
{
    if(head==NULL)
    {
        head = new Node(val);
        return;
    }
    else
    {
        Node* curr = head;
        while(curr -> next!=NULL)
        {
            curr = curr->next;
        }
        curr->next = new Node(val);

    }

}

void addToFirst(int val)
{
    Node* temp = new Node(val);
    temp -> next = head;
    head = temp;

}

void ll_insert_after_search(int val, int instdata)
{
    Node *newNode,*ptr,*preptr;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    preptr = ptr = head;
    newNode -> value = val;

    while((preptr -> value!=val) && ptr!=NULL){
        preptr = ptr;
        ptr = ptr -> next;
    }

    preptr  -> next = newNode;
    newNode -> next = ptr;


}
void ll_insert_before_search(int val, int instdata)
{
    Node *newNode,*ptr,*preptr;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    preptr = ptr = head;
    newNode -> value = val;

    while((ptr -> value!=val) && ptr!=NULL){
        preptr = ptr;
        ptr = ptr -> next;
    }

    preptr  -> next = newNode;
    newNode -> next = ptr;


}
void printLinkedList()
{
    Node* curr = head;
    while(curr!=NULL)
    {
        printf("%d\n",curr->value);
        curr = curr->next;
    }


}
int main()
{
    addToEnd(1);
    addToEnd(2);
    addToEnd(3);
    addToEnd(4);
    printLinkedList();
    ll_insert_after_search(2,1);
    ll_insert_after_search(3,1);
    printLinkedList();
    cout<<"-------------------------";

    ll_insert_before_search(2,1);
    ll_insert_before_search(3,1);
    printLinkedList();



//    head = new Node(1);
//    head->next = new Node(2);
//    head->next->next = new Node(3);
//    head->next->next->next = new Node(4);

    return 0;
}
