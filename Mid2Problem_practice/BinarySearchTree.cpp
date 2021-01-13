#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    int count;
    Node* leftChild;
    Node* rightChild;
    Node(int v){
    val  = v;
    count = 1;
    leftChild = NULL;
    rightChild = NULL;
    }
};
Node* root;
void insert(int v){
if(root==NULL){
    root = new Node(v);
    return;
}
Node* curr = root;
while(true){
    if(curr->val<v){
        if(curr->rightChild==NULL){
            curr->rightChild = new Node(v);
            return;
        }
        curr = curr -> rightChild;
    }else if(curr->val>v){
        if(curr->leftChild==NULL){
            curr -> leftChild = new Node(v);
            return;
        }
        curr = curr -> leftChild;

    }else if(curr->val==v){
        curr->count++;
        return;
    }
 }
}
int search(int v){
    if(root==NULL){
        return 0;
    }
    Node* curr = root;
    while(true){
        if(curr->val<v){
            if(curr->rightChild==NULL){
                return 0;
            }
            curr = curr ->rightChild;
        }else if(curr->val>v){
            if(curr->leftChild==NULL){
                return 0;
            }
            curr = curr -> leftChild;
        }else{
            return 1;
            //return curr->count;

        }
    }
}
void printInorder(){
        if(node==NULL)
            return;
        printInorder(node ->leftChild);
        cout<<node->val;
        printInorder(node->rightChild);
}
int main(){
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    printInorder();

}
