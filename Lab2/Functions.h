#include "struct.h"
#include <bits/stdc++.h>
using namespace std;

///All problems are worth 10 points
///For today, the time complexity of
///your solution does not matter as long as your program terminates.

/**
    The isEmpty function should return 1
    if the linked list whose first node is
    pointed by the head variable is empty,
    (i.e the head points to NULL), and
    0 otherwise
*/
//1
int isEmpty(Node* head){
    Node* curr = head;
    if(curr==NULL)
        return 1;
        else
            return 0;

}
//2
/**
    Given a pointer to the start of a linked list,
    specified by Node* head, and an integer value x,
    delete ALL nodes in the linked list with the
    value x. Return head after you have deleted all
    the nodes.
*/

Node* deleteAll(Node* head, int x){
    if(head==NULL){
        return head;
    }else if(head->value==x && head->next!=NULL){
        return NULL;
    }
    while(head->value==x && head->next!=NULL){
        Node* temp = head;
        head = head -> next;
        free(temp);
    }
    Node* curr = head;
    Node* previous = NULL;
    while (curr!=NULL){
        if(curr->value==x && previous!=NULL){
            Node* temp = curr;
            previous->next = curr->next;
            free(temp);
            curr = previous->next;
        }else{
        previous = curr;
        curr = curr ->next;
        }
    }
    return head;
}

/**
    Given a pointer to the start of a linked list,
    specified by Node* head, and 2 integers with values
    x and y, replace ALL nodes in the linked list with the
    value x with nodes with value y. Return head after you
    have replaced all the nodes.
*/


Node* replaceAll(Node* head, int x, int y){

    Node*temp = head;
    while(head!=NULL){
        if(head->value==x)
            head->value=y;
        head = head->next;
    }
    return temp;
}

/**
    Given a pointer to the start of a linked list,
    specified by Node* head, return the number of distinct
    integers in the linked list.
*/
int countFrequency(Node* head){
    int cnt = 0;
    while(head!=NULL){
        Node* temp = head->next;
        int flag = 0;
        while(temp!=NULL){
            if(temp->value==head->value){
               flag = 1;
            }
            temp = temp -> next;
        }
        if(flag==0){
            cnt++;
        }
         head = head -> next;
    }
    return cnt;
}

/**
    Given a pointer to the start of a linked list,
    specified by Node* head, create another linked list
    in which the values are in the reverse order of how
    they were in the original linked list. Return a pointer
    to the head of the new linked list.
*/

Node* reverseLinkedList(Node* head){
    Node* curr = head->next;
    Node* newHead;
    newHead = new Node(head->value);
    while(curr!=NULL){
        Node* temp = new Node(curr->value);
        temp->next = newHead;
        newHead = temp;
        curr = curr->next;
    }

    return newHead;
}


