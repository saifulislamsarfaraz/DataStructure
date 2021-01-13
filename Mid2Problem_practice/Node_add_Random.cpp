#include<bits/stdc++.h>
using namespace std;
struct Node{
        int v;
        Node* leftChild;
        Node* rightChild;

        Node(int val){
            v = val;
            leftChild = NULL;
            rightChild= NULL;
        }
};
Node* root = NULL;
void addNodeAtRandom(int val){
    Node* temp = new Node(val);
    if(root==NULL){
        root = temp;
    }
    Node* curr = root;
    while(curr->leftChild!=NULL && curr->rightChild!=NULL){
        if(rand()%2){
            curr = curr -> leftChild;

        }else{
        curr = curr -> rightChild;
        }
    }

}
