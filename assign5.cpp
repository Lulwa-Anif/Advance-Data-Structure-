#include<iostream>
using namespace std;
class tree{
    public:
    tree *right,*left;
    int data;
    tree(){
        right=NULL;
        left=NULL;
        data=0;
    }
    friend class bst;
};
class bst{
   public:
    tree *root,*nnode,*temp;
    bst(){
        root=NULL;
    }
    void create(){

    cout<<"press -1 to stop entering data";
    do{
        cout<<"enter data";
        nnode=new tree;
        cin>>nnode->data;

        if(nnode->data==-1){
            break;
        }
        else if(root==NULL){
            root=nnode;
        }
        else {
            temp=root;
            while(temp!=NULL){

                if(nnode->data < temp->data){
                    if(temp->left==NULL){
                        temp->left=nnode;
                        break;
                    }
                    else {
                        temp=temp->left;
                    }
                }
                else if(nnode->data >= temp->data){
                    if(temp->right==NULL){
                        temp->right=nnode;
                        break;
                    }
                    else {
                        temp=temp->right;
                    }
                }
            }
        }
    } while(1);
    }
    void minimum(){
        tree *temp;
        temp=root;
        while (temp->left != NULL)
        {
            temp=temp->left;
        }
        cout<<"minimum data in the tree is "<<temp->data;
        
    }
    void search(){
        tree *temp;
        int flag=0,key;
        temp=root;
        cout<<"\nenter a key to search : ";
        cin>>key;
        while(temp!=NULL){
            if(temp->data==key){
                flag=1;
                break;
            }
            else if(temp->data < key){
                temp=temp->right;
            }
            else {
                temp=temp->left;
            }
        }
        if(flag==1){
            cout<<"\nkey is found!"<<key;
        }
        else {
            cout<<"\nkey is not found!";
        }
    }
    int ascending(tree *temp){
        if(temp!=NULL){
            ascending(temp->left);
            cout<<temp->data<<"\t";
            ascending(temp->right);
        }
    }
    int descending(tree *temp){
        if(temp!=NULL){
            ascending(temp->right);
            cout<<temp->data<<"\t";
            ascending(temp->left);
        }
    }
    int findHeight(tree *root){
        int leftHeight = findHeight(root->left);
        int rightHeight = findHeight(root->right);
        return max(leftHeight,rightHeight)+1;
    }
};
int main(){
    bst b;
    int option;
    cout<<"1. Insert new node \n2. Find number of nodes in longest path from root\n3.Minimum data value found in the tree\n4. Search a value \n5. Print values in ascending and descending order\n6.Exit\n";
    do{
        cout<<"enter choice";
        cin>>option;
        switch(option){
        case 1:
            b.create();
        break;

        case 2:
            cout<<"number of nodes in longest path from root : "<<b.findHeight(b.root);
        break;

        case 3:
            b.minimum();
        break;

        case 4:
            b.search();
        break;

        case 5:
            cout<<"ascending order :  "<<b.ascending(b.root);
            
            cout<<"ascending order :  "<<b.descending(b.root);
        break;
        case 6:
        break;

    }
    }while(option<=6);
}