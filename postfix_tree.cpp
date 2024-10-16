#include<iostream>
using namespace std;
class tree {
    public:
    tree *right,*left;
    char data;
tree(){
right=NULL;
left=NULL;
data=0;
}
friend class Stack;
friend class expression;
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
class expression {
    public:
    Stack s;
    int i;
    char x;
tree *nnode,*lc,*rc,*result;
string exp;
    expression(){
        nnode=NULL;
        result=NULL;
        lc=0;
        rc=0;
    }
void postfixExpression() { 

cout<<"enter the postfix expression: ";
cin>>exp;

for(i=0;i<exp.length();i++){
    x=exp[i];
    if((x>='a' && x<='z') || (x>='A' && x<='Z')){
        nnode=new tree();
        nnode->data=x;
        s.push(nnode);

    }
    else if(x=='-' || x=='+' || x=='*' || x=='/' || x=='^'){
        nnode=new tree();
        nnode->data=x;
        rc=s.pop();
        nnode->right=rc;
        lc=s.pop();
        nnode->left=lc;
        s.push(nnode);
    }
}
result=s.pop();
}
void inorder(tree* temp){
    
        if(temp!=NULL) {
            inorder(temp->left);
            cout<<temp->data;
            inorder(temp->right);
        }
    }

};
int main(){

expression ex;
ex.postfixExpression();
cout << " The Inorder Traversal of Expression Tree: ";
ex.inorder(ex.result);
}
