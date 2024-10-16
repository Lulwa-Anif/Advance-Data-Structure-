#include<iostream>
using namespace std;
#include<stack>
class tree {
public:
tree *left,*right;
string key,value;
tree() {
left=NULL;
right=NULL;
}
friend class bst;
};
class bst {
public:
char ans;
tree *root;
bst() {
root=NULL;

}
void create() {

tree *temp,*nnode;


do {
    
cout<<"enter key: ";
nnode=new tree;
cin>>nnode->key; ;

cout<<"enter value: ";
cin>>nnode->value; ;



if(root==NULL) {
root=nnode;
}
else {

temp=root;

while(temp!=NULL) {

if(nnode->key.compare(temp->key) < 0) {

if(temp->left==NULL) {

temp->left=nnode;
break;
}
else {
temp=temp->left;
}
}

else if(nnode->key.compare(temp->key) >= 0) {

if(temp->right==NULL) {
temp->right=nnode;
break;
}
else {
temp=temp->right;
}
}
}
}
cout<<"do you want to enter data";
cin>>ans;
}while(ans=='y');

}

 
void inorder(tree *temp) {
 
        if (temp != NULL) {
            inorder(temp->left);
            cout << temp->key << "\t" << temp->value << endl; // Corrected line to print key and value
            inorder(temp->right);
        }
}
void search() {
tree *temp;
int flag=0;
string sKey;
temp=root;
cout<<"enter key to search: ";
cin>>sKey;
while(temp!=NULL) {
if(temp->key==sKey) {
flag=1;
break;
}
else if(temp->key>sKey) {
temp=temp->left;
}
else{
temp=temp->right;
}

}
if(flag==1) {
cout<<"key is found: "<<sKey;
}
else {
cout<<"key is not found";
}
}
};
int main() {
bst s;
s.create();
s.inorder(s.root);
s.search();
}
