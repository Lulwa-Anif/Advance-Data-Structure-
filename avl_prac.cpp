#include<iostream>
using namespace std;

class node
{
public:
  int data;
  node *left,*right;
  node()
  {
  	data=0;
  	left=NULL;
  	right=NULL;
  }
};
class AVL
{

 node *AVLroot;
 

  node *insert1(node *,int);//Recursive counterpart of insert
  void  preorder1(node *); //Recursive counterpart of preorder
  void  inorder1(node *); //Recursive counterpart of inorder
  int   height( node *);
  node *rotateright(node *);//logic
  node *rotateleft(node *);//logic
  node *RR(node *);//
  node *LL(node *);
  node *LR(node *);
  node *RL(node *);
  int BF(node *);
  public:
     AVL()
      {
	AVLroot=NULL;
      }
    
     void insert(int x)
     {
     AVLroot=insert1(AVLroot,x);
     }
     void preorder()
     {
     preorder1(AVLroot);
      }
     void inorder()
     {
     inorder1(AVLroot);
     }
};

node * AVL::insert1(node *T,int x) {
    
}