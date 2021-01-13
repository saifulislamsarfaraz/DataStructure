#include<bits/stdc++.h>
#include<new>
#include <fstream>

using namespace std;
struct node
{
    string word,meaning;
    node *right,*left;

};
struct node *root = NULL,*temp;
int n;
string iWord,iMeaning,src,cut,mn,del,no;

struct node* insert (struct node *root,string key,string item){

    if(root==NULL){
        root = new struct node[1];
        root->right = NULL;
        root->left = NULL;
        root->word = key;
        root->meaning = item;
        return root;
    }
    //if key is smaller
    else if(key.length()<=root->word.length()){
        root->left = insert(root->left,key,item);
    }
    //key is greater than root
    else{
        root->right = insert(root->right,key,item);
    }
    return root;
};
void in_order(struct node *root){
    if(root!=NULL){
        in_order(root->left);
        cout<<"Word : "<<root->word<<"  Meaning : "<<root->meaning<<"\n";
        in_order(root->right);
    }
}
void pre_order(struct node *root){
    if(root!=NULL){
        cout<<"Word : "<<root->word<<"  Meaning : "<<root->meaning<<"\n";
        pre_order(root->left);
        pre_order(root->right);
    }
}
    void post_order(struct node *root){
    if(root!=NULL){
        post_order(root->left);
        post_order(root->right);
        cout<<"Word : "<<root->word<<"  Meaning : "<<root->meaning<<"\n";
        }
    }
                                       //lenght
void order(struct node *root,string no,int M){
    if(root!=NULL){
        int f=0;
        for(int i=0;i<M;i++){
            if(no[i]==root->word[i])
            {
               f++;
            }
        }
        if(f==M-2 || f==M-1 || f==M){
           cout<<"Word : "<<root->word<<"  Meaning : "<<root->meaning<<"\n";
        }

        order(root->left,no,M);
        order(root->right,no,M);
    }
}


struct node* searching(struct node *root,string src,string mn){

    if(root==NULL || root->word==src){
        return root;
    }
    if(src.length()> root->word.length()){
        return searching(root->right,src,mn);
    }
    else
        return searching(root->left,src,mn);

}


struct node* inPre(struct node *root){
        while(root && root->right!=NULL){
            root = root->right;
        }
        return root;
};

struct node* inSuc(struct node *root){
        while(root && root->left!=NULL){
            root = root->left;
        }
        return root;
};
struct node* minimum(struct node *root){
    if(root->left == NULL){
        return root;
    }
    else
        return minimum(root->left);
};

struct node* maximum(struct node *root){
    if(root->right == NULL){
        return root;
    }
    else
        return maximum(root->right);
};




struct node *Delete (struct node * root, string del,string dm)
{


    if(root == NULL)
    {
        return  root;
    }
    if(del < root->word)
    {
        root->left =  Delete (root->left , del , dm);
    }
    if(del > root->word)
    {
        root->right=  Delete (root->right , del , dm);
    }
    else
    {
        // case 1: no child
        if (root ->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
            return root;
        }
        // case 2: one child
        else if (root ->left == NULL )
        {
            struct node *temp = root;
            root = root->right;
            delete temp;
            return root;
        }
        else if(root ->right == NULL )
        {
            struct node *temp = root;
            root = root->left;
            delete temp;
            return root;
        }
        //case 3:two child
        else
        {
            //Delete the in-order successor or delete pre-decor
            int m;
            cout<<"Press 1 to make Left Max at root or Press 2 to make Right Min at root : ";
            cin>>m;
            if(m==1){
                struct node *temp = maximum( root->left);
                root->word = temp->word;
                root->meaning=temp->meaning;
                root->left = Delete (root->left, temp->word,temp->meaning);
                return root;
            }
        if(m==2){
            struct node *temp = minimum( root->right);
            root->word = temp->word;
            root->meaning=temp->meaning;
            root->right = Delete (root->right, temp->word,temp->meaning);
            return root;
            }

        }

    }
    return root;

}



int main()
{

    cout<<"\t\t\tWord Dictionary"<<endl;
    cout<<"\t\t->->Your Team Members<-<-"<<endl;
    cout<<"\t1.Md Jekrul Islam \t 2019-2-60-046"<<endl;
    cout<<"\t2.Nadia Hannan Sharme \t 2019-2-60-042"<<endl;
    cout<<"\t3.Shamsun Nahar Zaman \t 2019-2-60-049"<<endl;
    cout<<"\t4.Orpa Numan\t         2019-2-60-051"<<endl;
    cout<<"\t5.Md Saiful\t         2019-2-60-040 "<<endl;

    int n,op,ch;


    for(;;)
    {
        cout<<"\n1. Insert word in your dictionary\n";
        cout<<"\n2. Other operation you want to do\n";
        cout<<"\n0. Exit from operation\n";

        cout<<"\nEnter a choice : ";
        cin>>ch;

        if(ch==1)
        {
            cout<<"Number of inputs word : ";
            cin>>n;
            cout<<endl;
            ofstream outfile;
            outfile.open("afile.txt");
            for(int i=0; i<n; i++)
            {

                    cout<<"Enter word : ";
                    cin>>iWord;
                    cout<<"Enter meaning : ";
                    cin>>iMeaning;
                    cout<<endl;
                    outfile << iWord <<"  "<< iMeaning << endl;

                    root=insert(root,iWord,iMeaning);


            }
            outfile.close();
        }

        if(ch==2)
        {
            cout<<"1. Inorder print all words in your dictionary\n";
            cout<<"2. Preorder print all words in your dictionary\n";
            cout<<"3. Postorder print all words in your dictionary\n";
            cout<<"4. Search a word in your dictionary\n";
            cout<<"5. Maximun lengthy word\n";
            cout<<"6. Minimum lengthy word\n";
            cout<<"7. Delete a word in your dictionary\n";

            cin>>op;

            switch(op)
            {

            case 1:
                {
                    cout<<endl;
                    cout<<"Inorder : ";
                    in_order(root);
                    cout<<endl;
                    break;
                }

            case 2:
                {
                    cout<<endl;
                    cout<<"PreOrder : ";
                    pre_order(root);
                    cout<<endl;

                    break;
                }

            case 3:
                {
                    cout<<endl;
                    cout<<"PostOrder : ";
                    post_order(root);
                    cout<<endl;

                    break;
                }

            case 4:
                {

                    cout<<"Enter the word u want to search : \n";
                    cin>>src;
                    cout<<"Enter the word meaning u want to search : \n";
                    cin>>mn;
                    if(searching(root,src,mn)!=NULL)
                {
                    cout<<src<<" was found\n";
                    cout<<"Word:"<<src<<endl;
                    cout<<"Meaning:"<<mn<<endl;
                }
                else
                {
                    cout<<src<<" Wasn't found\n\n";
                    cout<<"Similar word : \n";
                    int M = src.size();
                    order(root,src,M);
                    cout<<endl;

                }
                break;
                }

            case 5:
                {

                    temp = maximum(root);
                    cout<<"Maximum length word : "<<temp->word<<endl;
                    break;
                }

            case 6:
                {

                    temp = minimum(root);
                    cout<<"Minimum length word : "<<temp->word<<endl;

                    break;
                }

            case 7:
                {

                    cout<<"Enter the word you want to delete :";
                    cin>>cut;

                    Delete(root,cut,iMeaning);

                    break;
                }

            }

        }

        if(ch==0)
        {
            exit(0);
        }

    }
}


