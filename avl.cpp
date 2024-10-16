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

node * AVL::insert1(node *T,int x)
{
	if(T==NULL)
	{
		T=new node;
		T->data=x;
		T->left=NULL;
		T->right=NULL;
	}
	else
		if(x > T->data)      // insert in right subtree
		{
			T->right=insert1(T->right,x);
			if(BF(T)==-2)
				if(x>T->right->data)
					T=RR(T);
				else
					T=RL(T);
		}
		else
			if(x<T->data) // insert in left subtree
			{
				T->left=insert1(T->left,x);
				if(BF(T)==2)
					if(x < T->left->data)
						T=LL(T);
					else
						T=LR(T);
			}
	
	return T;
}
int AVL::height(node *T)//finds height 
{
	int lh,rh;
	if(T==NULL)
		return(0);
		
	lh=1+height(T->left);
	rh=1+height(T->right);
	
	if(lh>rh)
		return lh;
	else 
  	    return rh;
}
//perform rorate right operation
node * AVL::rotateright(node *x)
{
	node *y;
	y=x->left;
	x->left=y->right;
	y->right=x;
	return(y);
}
//perform rotate left operation
node * AVL::rotateleft(node *x)
{
	node *y;
	y=x->right;
	x->right=y->left;
	y->left=x;
	return(y);
}
//perform RR operation
node * AVL::RR(node *T)
{
	T=rotateleft(T);
	return(T);
}
//perform LL operation

node * AVL::LL(node *T)
{
	T=rotateright(T);
	return(T);
}
//perform LR operation

node * AVL::LR(node *T)
{
	T->left=rotateleft(T->left);
	T=rotateright(T);
	return(T);
}
//perform RL operation

node * AVL::RL(node *T)
{
	T->right=rotateright(T->right);
	T=rotateleft(T);
	return(T);
}
int AVL::BF(node *t)
{
	int bf;
	bf=height(t->left)-height(t->right);
	return(bf);
}   
void AVL::preorder1(node *T)
{
	if(T!=NULL)
	{
		cout<<" "<<T->data<<"(Bf="<<BF(T)<<")";
		preorder1(T->left);
		preorder1(T->right);
	}
}
void AVL::inorder1(node *T)
{
	if(T!=NULL)
	{
		inorder1(T->left);
		cout<<" "<<T->data<<"(Bf="<<BF(T)<<")";
		inorder1(T->right);
	}
}

main()
{
	AVL A;
	int x,n,i,choice;
	char ch;
	do
		{
			cout<<"\n\n ----------------------------------------------";
			cout<<"\n\n                     AVL TREE                  ";
			cout<<"\n\n ----------------------------------------------";
			cout<<"\n\n\t1.Create";
			cout<<"\n\n\t2.Display";
			cout<<"\n\n\t3.Delete";
			cout<<"\n\n\t4.Insert ";
			cout<<"\n\n\t5.Exit ";
			cout<<"\n\n ----------------------------------------------";
			cout<<"\n\n\tEnter Your Choice : ";
			cin >> choice;
			cout<<"\n\n ----------------------------------------------";
			switch(choice)
			    {
				case 1:cout<<"\nEnter no.of elements :";
				       cin>>n;
				       cout<<"\n Enter tree data :";
				       for(i=0;i<n;i++)
					   {
						cin>>x;
						A.insert(x);
					   }
				       break;
                case 2:	cout<<"\nPreorder sequence :\n";
					A.preorder();
					cout<<"\nInorder sequence :\n";
					A.inorder();
					//A.levelwise();
					break;
            case 4:cout<<"\nEnter a data : ";
				       cin >>x;
				       A.insert(x);
				       break;
				
			
				
				case 5: exit(0);
					break;
				default:
				       cout<<"\n\n\t Invalid statement";
			     }
			     cout<<"\n\n\t Do you want to continue::";
			     cin>>ch;

	}while(ch=='y'||ch=='Y');
	
}

/* OUTPUT:=
 ----------------------------------------------
                     AVL TREE
 ----------------------------------------------

        1.Create

        2.Display

        3.Delete

        4.Insert

        5.Exit
 ----------------------------------------------
        Enter Your Choice : 1
 ----------------------------------------------

        Enter no.of elements :6


         Enter tree data :78 21 14 11 97 85


         Do you want to continue::

 ----------------------------------------------
        Enter Your Choice : 2
 ----------------------------------------------

        Preorder sequence :
 21(Bf=0) 14(Bf=1) 11(Bf=0) 85(Bf=0) 78(Bf=0) 97(Bf=0)

        Inorder sequence :
 11(Bf=0) 14(Bf=1) 21(Bf=0) 78(Bf=0) 85(Bf=0) 97(Bf=0)

         Do you want to continue::y

 ----------------------------------------------

        Enter Your Choice : 4
 ----------------------------------------------

        Enter a data : 74

         Do you want to continue::y
 ----------------------------------------------
       Enter Your Choice : 3
 ----------------------------------------------

        Enter a data : 85

         Do you want to continue::y

 ----------------------------------------------
        Enter Your Choice : 2
 ----------------------------------------------

        Preorder sequence :
 21(Bf=0) 14(Bf=1) 11(Bf=0) 78(Bf=0) 74(Bf=0) 97(Bf=0)

        Inorder sequence :
 11(Bf=0) 14(Bf=1) 21(Bf=0) 74(Bf=0) 78(Bf=0) 97(Bf=0)

         Do you want to continue::n   */
