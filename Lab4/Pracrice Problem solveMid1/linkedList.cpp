#include<bits/stdc++.h>
using namespace std;

struct LinkedList{
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
      LinkedList(){
      head = NULL;
      }

      void addToEnd(int x){
            if(head==NULL){
                head = new Node(x);
            }else{
                Node* curr = head;
                while(curr->next!=NULL){
                    curr = curr->next;
                }
                curr->next = new Node(x);
            }
      }

      void addToFirst(int x){
            Node* temp = new Node(x);
            temp->next = head;
            head = temp;
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

    void removeLast(){
        Node* newNode = new Node();
        if(head==NULL){
            return;
        }if(head->next==NULL){
            free(head);
            return;
        }
        Node* curr = head;
        ////////////  Node* prev = head; //////////
        while(curr->next->next!=NULL){
            curr = curr->next;
        }
        free(curr->next);
        curr->next = NULL;
    }

    void removeFirst(){
            if(head==NULL){
                return;
            }
            Node* temp = head;
            head = head->next;
            free(temp);

    }

    void deleteNnode(int x){
            if(head->value==x){
                Node* temp = head;
                head = head -> next;
                free(temp);
                return;
            }
            Node *curr, *prev;
            curr = prev = head;
            while(curr!=NULL && curr->value!=x){
                prev = curr;
                curr = curr ->next;
            }
            prev->next = curr->next;
            free(curr);

    }

    void reverseLinkedList(Node* head){
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


   void addBefore(int x,int insValue){
            Node* newNode = new Node(insValue);
            if(head->value==x && head!=NULL){
                Node* temp = new Node(insValue);
                temp->next = head;
                head = temp;
                return;
            }
        Node *curr, *prev;
        curr = prev = head;
        while(curr->value!=x&&curr!=NULL){
             prev = curr;
             curr = curr->next;
        }
        prev -> next = newNode;
        newNode -> next = curr;
    }

    void addAfter(int x, int insValue){
    Node* newNode = new Node(insValue);
    Node *curr, *prev;
    curr = prev = head;
    if(head->value==x){
        Node* temp = new Node(insValue);
        temp->next = head->next;
        head->next = temp;
        return;
    }
    while(prev->value!=x&&curr!=NULL){
        prev = curr;
        curr = curr ->next;
    }
    prev->next = newNode;
    newNode ->next = curr;
    }

    void deleteAllNode(int x){
        while(head->value==x&& head!=NULL){
            Node* temp = head;
            head = head ->next;
            free(temp);
        }
        Node *curr, *prev;
        curr = prev = head;
        while(curr!=NULL){
        if(curr->value==x){
            prev->next = curr->next;
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }else{
         prev = curr;
         curr = curr->next;
        }
     }
  }
//
//  void deleteChar(){
//  if(head==NULL){
//    return;
//  }
//  Node *curr *prev;
//  curr = head->next;
//  prev = head;
//  while(prev->value=='UPcase'&&curr->next->value!='Lowcase'){
//    Node* temp = prev;
//    free(temp);
//    prev = prev ->next;
//    if(curr->value=='Lowcase'){
//        Node* lowdelet = curr;
//        free(lowdelet);
//    }
//     curr = curr->next;
//  }
//
//
//  }

//  int middleNode(){
//        Node *curr,*prev;
//        curr = prev = head;
//        if(head!=NULL){
//            while(curr!=NULL&&curr->next!=NULL){
//                    curr = curr->next->next;
//                    prev = prev ->next;
//            }
//          //  printf("%d",prev->value);
//            return prev->value;
//
//        }
//     }

     int NthNode(int n){
        Node* curr = head;
        int count = 0;
        while(curr!=NULL){
            if(count==n)
                return (curr->value);
            count++;
            curr = curr ->next;
        }
        return 0;
     }
    int countFrequency(){
    int cnt = 0;
    int maxCount = 0;
    while(head!=NULL){
        Node* temp = head->next;
        int cnt = 1;
        while(temp!=NULL){
            if(temp->value==head->value){
               cnt++;
            }
            temp = temp -> next;
        }
        if(maxCount<cnt){
            maxCount = cnt;
        }
         head = head -> next;
      }
    return maxCount;
   }
};
int main(){
        LinkedList l;
        l.addToFirst(3);
        l.addToFirst(3);
        l.addToEnd(5);
        l.addToEnd(9);
        l.addToEnd(9);
        l.addToEnd(9);
        l.addToEnd(9);
        l.addToEnd(6);
        l.addToEnd(6);
        printf("%d\n", l.countFrequency());
//     printf("%d",l.countTheNumber());
//     l.removeFirst();
//     l.removeLast();
//     l.deleteNnode(9);
//     l.addBefore(3,7);
//     l.addAfter(7,1);
//     l.deleteAllNode(6);
//     l.display();
// printf("%d",l.middleNode());
// printf("%d",l.NthNode(2));

        return 0;
}

