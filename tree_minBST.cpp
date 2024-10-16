#include<iostream>
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

     void inorder(tree *temp){

        if(temp!=NULL) {

            inorder(temp->left);

            cout<<temp->data;

            inorder(temp->right);

         }

     }

    
void min(){
tree *temp;
temp=root;
while(temp->left!=NULL){

temp=temp->left;
}
cout<<"minimum is : "<<temp->data;


    }
void max(){
tree *temp;
temp=root;
while(temp->right!=NULL){

temp=temp->right;
}
cout<<"maximum is : "<<temp->data;

}

};

int main(){

tree t;

BST g;

g.create();
g.min();
g.max();
cout<<"\nInorder";
g.inorder(g.root);

 

}
