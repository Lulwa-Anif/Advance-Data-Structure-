#include<iostream>
using namespace std;
class tree{
    public:
    tree *right,*left;
    int data;
    tree(){
        right=NULL;
        left=NULL;
    }
    friend class treetraverse;
};
class treetraverse{
public:
tree* root;
int search(int inorder[],int start, int end,int curr){
    for(int i=start;i<=end;i++){
        if(inorder[i] == curr){
            return i;
        }
    }
}
tree *buildTree(int preorder[], int inorder[],int start, int end){
    static int idx = 0;
    int curr=preorder[idx];
    tree *nnode=new tree(curr);
    
    if(start==end){
        return nnode;
    }
    int pos=search(inorder,start,end,curr);
    nnode->left=buildTree(preorder,inorder,start,pos-1);
    nnode->right=buildTree(preorder,inorder,pos+1,end);

    return nnode;
}
void inorder(tree* root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
}
};
int main(){
    treetraverse t;
    int preorder[]={1,2,4,3,5};
    int inorder[] = {4,2,1,5,3};
    t.buildTree(preorder,inorder,0,4);
    t.inorder(t.root);
    return 0;
}