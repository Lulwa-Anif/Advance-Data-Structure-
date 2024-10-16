#include<iostream>
using namespace std;
class node  
{
    public:
    int data;
    node *left;
    node *right;
    int lt,rt;
    node(){
        left=NULL;
        right=NULL;
        lt=1;
        rt=1;
    }
    friend class tbt;
};
class tbt {
    public:
    node *root,*dummy,*temp,*nnode;

    tbt(){
        root=NULL;
        dummy=new node;
    }

    void create(){

        cout<<"press -1 to stop entering data :\n ";
        do{
            cout<<"enter the data :";
            nnode=new node;
            cin>>nnode->data;
            if(nnode->data==-1){
                break;
            }
            if(root==NULL){
                root=nnode;
                root->right=dummy;
                root->left=dummy;
            }
            else{
                temp=root;
                while(1){
                
                if(nnode->data<temp->data) {
                     
                  if(temp->lt==1) {
                        nnode->left=temp->left;
                        nnode->lt=temp->lt;
                        nnode->right=temp;
                        temp->left=nnode;
                        temp->lt=0;
                          break;
                        }
                      
                    
                    else {
                        temp=temp->left;
                    }
                }
                
                else if(nnode->data>=temp->data) {
                   
                    if(temp->rt==1) {

                        nnode->right=temp->right;
                        nnode->left=temp;
                        temp->right=nnode;
                        temp->rt=0;
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
    };

int main(){
    // node n;
    tbt t;
    t.create();
}