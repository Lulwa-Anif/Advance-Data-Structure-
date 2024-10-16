#include<iostream>
using namespace std;
class tree {
public:
tree *right,*left;
char data;
tree(){
    right=NULL;
    left=NULL;

}
};
class stack {
    public:
    tree *data[10];
    int top,size;
    stack(){
        top=-1;
    }
    tree *gettop(){
        return data[top];
    }
    void push(tree *ele){
        top++;
        data[top]=ele;
    }
    tree *pop(){
        tree *no=data[top];
        top--;
        return no;
    }
    bool isEmpty(){
        if(top==-1){
            return true;
        }
        else {
            return false;
        }
    }
    bool isFull(){
        if(top==size-1){
            return true;
        }
        else{
            return false;
        }
    }
};
class expression {
    stack s;
public:
tree *lc,*rc,*nnode,*result,*root;
char exp;
    string prefix;
    void expTree(){
        cout<<"enter prefix expression";
        cin>>prefix;
        for(int i=prefix.length()-1;i>=0;i--) {
            exp = prefix[i];
            
            if((exp>= 'a' && exp<= 'z') || (exp>= 'A' && exp<= 'Z')){
                nnode = new tree;
                nnode->data=exp;
                s.push(nnode);
            }
            else if(exp=='+' || exp=='-' || exp=='^' || exp=='*' || exp=='/'){
                nnode=new tree;
                nnode->data=exp;
                rc=s.pop();
                lc=s.pop();
                nnode->right=rc;
                nnode->left=lc;
                s.push(nnode);
            }
        }
        result=s.pop();
    }
     void inorder(tree *temp){
        if(temp!=NULL) {
            inorder(temp->left);
            
            inorder(temp->right);
            cout<<temp->data;
        }
    }
tree *swap(tree *temp){
    tree *nnode=NULL;
    if(temp!=NULL){
        nnode=new tree;
        nnode->data=temp->data;
        nnode->left= swap(temp->right);
        nnode->right= swap(temp->left);
        return nnode;
    }
    return NULL;
}
};

int main(){
    expression ex;
    ex.expTree();
    ex.inorder(ex.result);
    cout<<ex.result->data;
    ex.swap(ex.root);
}