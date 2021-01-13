#include <bits/stdc++.h>
using namespace std;

/**
    //Md Saiful
    The following structure will be used to represent all the nodes
    in the binary trees in all the functions that you have to
    implement today.

    Each challenge is worth 10 points.
*/
struct Node{
    int value;
    Node* left;
    Node* right;
    Node(int v){
        value=v;
        left=NULL;
        right=NULL;
    }
};

/**
    The following function takes the pointer to the root of a tree
    as its argument. An initially empty array values[], and an
    integer variable valueSize (initially 0) are provided as global
    variables. Implement the function so that the values array is
    filled up with the values of the nodes in the tree. The order of
    the entries in the values array should correspond with the order
    of the values of the nodes as they would appear if the tree is
    traversed in an inorder manner.
*/

int values[100105];
int valueSize;

void inorderTraversal(Node* root){
    if(root!=NULL){
    inorderTraversal(root->left);
        values[valueSize] = root->value;
        valueSize++;
    inorderTraversal(root->right);
      }
}

/**
    The following function takes a pointer to the root of a Binary
    Search Tree (BST) as its argument, and a value v to insert into
    the tree. If the value v is not already in the tree, create a new
    node in the tree with value v, while keeping the property of the
    Binary search tree intact (i.e. all values contained in the nodes
    in the left subtree will be smaller than the value in the node,
    and all values in the right subtree will be larger than it.)

    If v already exists in the tree, do not insert any new node.
    Note: The root may be null.
*/

void addToBST(Node* root, int v){
        if(root==NULL){
            root = new Node(v);
            return;
        }
        Node* curr = root;
        while(true){
            if(curr->value<v){
                if(curr->right==NULL){
                    curr->right = new Node(v);
                    return;
                }
                curr = curr->right;
            }else if(curr->value>v){
            if(curr->left==NULL){
                curr->left = new Node(v);
                return;
              }
              curr = curr->left;
            }else if(curr->value==v){
                return;
            }
        }
}

/**
    The following function takes a pointer to the root of a Binary
    Search Tree (BST) as its argument, and a value v to search in
    the tree. If the value v is not in the tree, return 0 and
    return 1 otherwise.

    Note: The root may be null.
*/

int searchInBST(Node* root, int v){
    if(root==NULL){
        return 0;
    }
    Node* curr = root;
    while(true){
        if(curr->value<v){
            if(curr->right==NULL){
                return 0;
            }
            curr = curr->right;
        }else if(curr->value>v){
            if(curr->left==NULL){
                return 0;
            }
            curr = curr -> left;
        }else if(curr->value==v){
            return curr->value;
        }
    }
    return 0;
}


/**
    The following function takes a pointer to the root of a Binary
    Search Tree (BST) as its argument. Return the maximum value in
    the tree. You can assume the tree is non-empty.
*/

int maxInTree(Node* root){


    if(root->right==NULL){
        return root->value;
    }
    return maxInTree(root->right);
//    int result = root->value;
//   // int leftV = maxInTree(root->left);
//    int rightV = maxInTree(root->right);
////    if(leftV>result){
////        result = leftV;
////    }
//    if(rightV>result){
//        result = rightV;
//    }
//  return result;
}

/**
    //Md Saiful
    The following function takes a pointer to the root of a Binary
    Tree as its argument.  Return 1 if the tree is a valid binary
    search tree, and 0 otherwise. You can assume the tree is
    non-empty.
*/
int maxValue(Node* root){


    if(root->right==NULL){
        return root->value;
    }
    return maxValue(root->right);
//    int result = root->value;
//   // int leftV = maxInTree(root->left);
//    int rightV = maxInTree(root->right);
////    if(leftV>result){
////        result = leftV;
////    }
//    if(rightV>result){
//        result = rightV;
//    }
//  return result;
}

int minValue(Node* root){


    if(root->left==NULL){
        return root->value;
    }
    return minValue(root->left);

}

int isBST(Node* root){
      if (root == NULL)
    return 1;

  if (root->left!=NULL && maxValue(root->left) > root->value)
    return 0;
  if (root->right!=NULL && minValue(root->right) < root->value)
    return 0;
  if (!isBST(root->left) || !isBST(root->right))
    return 0;

  return 1;

}


/**
    The following function takes a pointer to the root of a Binary
    Search Tree (BST) as its argument, and a value v. Find the
    smallest entry in the binary search tree that is greater than
    v.

    You can assume there will at least be one number in the BST
    greater than v and that v will exist in the BST.
*/
int val[100105];
int vSize = 0;
int upperBoundBST(Node* root, int v){
    if(root!=NULL){
    upperBoundBST(root->left,v);
        val[vSize] = root->value;
        vSize++;
    upperBoundBST(root->right,v);
      }
    int start = 0,end = vSize-1;
    int ans = -1;
    while(start<=end){
        int mid = (start+end)/2;
        if(val[mid]==v){
            ans = mid;
            start = mid+1;
        }else if(val[mid]>v){
            end = mid-1;
        }else{
            start = mid + 1;
        }
    }

}
