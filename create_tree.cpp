#include<iostream>
using namespace std;
class Stack
{
    char data[10];
    int top;
public :
	Stack()
	{
		top=-1;
	}
	char gettop()
	{
		return data[top];
	}
	void push(tree *no)
	{
	top++;
	data[top]=no;
	}
	char pop()
	{
	tree no=data[top];
	top--;
	return no;
	}
	int isempty()
	{
	if(top==-1)
	   return 1;
	return 0;
	}
	
	friend class tree;
    friend class GBT;
};

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

class GBT : public Stack {
    public:
    tree *root;
    Stack s;
    GBT(){
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

                cout<<"enter side of (L/R): ";
                cin>>side;
                if(side=='L'){
                    
                    if(temp->left==NULL){
                        temp->left=nnode;
                    }
                    else {
                        temp=temp->left;
                    }
                    
                }
                else if(side=='R') {
                   
                    if(temp->right==NULL){
                        temp->right=nnode;
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
    void inorder(){
        tree *temp;
        temp=root;
        while(temp!=NULL){
            s.push(temp);
            temp=temp->left;
        }
        while(!isempty()) {
            temp=s.pop();
            cout<<temp->data;
            if(temp->right!=NULL){
                temp=temp->right;
                while(temp!=NULL){
                    s.push(temp);
                    temp=temp->left;
                }
            }

        }

    }

    void preorder(){
        tree *temp;
        temp=root;
        while(temp!=NULL){
            cout<<temp->data;
            s.push(temp);
            temp=temp->left;
        }
        while(!isempty()) {
            temp=s.pop();
            // cout<<temp->data;
            if(temp->right!=NULL){
                temp=temp->right;
                while(temp!=NULL){
                    cout<<temp->data;
                    s.push(temp);
                    temp=temp->left;
                }
            }

        }

    }
};
int main(){
tree t;
GBT g;

g.create();
// g.inorder(g.root);
g.inorder();
}