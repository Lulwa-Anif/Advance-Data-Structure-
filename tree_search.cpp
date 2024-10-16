#include<iostream>
#include<stack>
using namespace std;
class tree {
    public:
    tree *right,*left;
    int data;
tree(){
right=NULL;
left=NULL;
data=0;
}
friend class GBT;
};

class BST {
    public:
    tree *root;
  
    BST(){
        root=NULL;
    }
    void create(){
        tree *temp,*nnode;
        char side;
        cout<<"press -1 to stop entering data :\n ";
        do{
            cout<<"enter the data :";
            nnode=new tree;
            cin>>nnode->data;
            if(nnode->data==-1){
                break;
            }
            if(root==NULL){
                root=nnode;
            }
            else{
                temp=root;

                while(temp!=NULL){
                
                if(nnode->data<temp->data) {
                     
                    if(temp->left==NULL){
                        temp->left=nnode;
                        break;
                    }
                    else {
                        temp=temp->left;
                    }
                }
                
                else if(nnode->data>=temp->data) {
                   
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
        }while(1);
    }
    void search_key(){
        tree *temp;
        temp=root;
        int key,flag=0;
    cout<<"enter key: ";
    cin>>key;
    while(temp!=NULL) {

        if(temp->data==key){
            cout<<"key found";
            flag=1;
            break;
        }
        else if(key<temp->data){
            temp=temp->left;
        }
        else {
            temp=temp->right;
        }
    }

    }

};
int main(){
tree t;
BST g;
g.create();
g.search_key();

}