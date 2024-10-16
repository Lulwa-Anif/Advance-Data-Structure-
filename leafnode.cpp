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
class Stack
{
    tree *data[10];
    int top;
public :
	Stack()
	{
		top=-1;
	}
	tree* gettop()
	{
		return data[top];
	}
	void push(tree* no)
	{
	top++;
	data[top]=no;
	}
	tree* pop()
	{
	tree* no=data[top];
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



class GBT{
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

                cout<<"enter side of (L/R) "<<temp->data;
                cin>>side;
                if(side=='L'){
                    
                    if(temp->left==NULL){
                        temp->left=nnode;
                        break;
                    }
                    else {
                        temp=temp->left;
                    }
                    
                }
                else if(side=='R') {
                   
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
    
    void leafnode(){
        tree *temp;
        temp=root;
        while(temp!=NULL){
            s.push(temp);
            temp=temp->left;
        }
        cout<<"leaf node : ";
        while(!s.isempty()) {
            temp=s.pop();
        if(temp->right==NULL && temp->left==NULL) { 

            cout<<temp->data<<"\t";
        }

        if(temp->right!=NULL){
                temp=temp->right;
                while(temp!=NULL) {
                    s.push(temp);
                    temp=temp->left;

                }  
            }
        }

    }

    
};
int main(){
// tree t;
GBT g;
// Stack s;
g.create();
// g.inorder(g.root);
g.leafnode();
}