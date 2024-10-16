#include<iostream>
using namespace std;
class Node
{
	int data;
	Node *left,*right;
	int lt,rt;
	public:
		Node()
		{
			left=NULL;
			right=NULL;
			lt=1;
			rt=1;
		}
	friend class TBTree;
};
class TBTree
{

	Node *root,*dummy;
	public:
	TBTree()
	{
	   dummy=new Node();
	   root=NULL;
	}
	void create()
	{
		Node *newnode,*temp;
		char side;
		do
		{
		   cout<<"\nEnter a data";
		   newnode=new Node;
		   cin>>newnode->data;
		   if(newnode->data==-1)
		      break;
		      
		   if(root==NULL)
		   {
		       root=newnode;
		       root->left=dummy;
		       root->right=dummy;
			}	
		   else
		   {
		   	   temp=root;
		   	   while(1)
		   	   {
				  
			   if(newnode->data <temp->data)
		   	   {
		   	   	  if(temp->lt==1)
		   	         {
						 	newnode->left=temp->left;
						    newnode->lt=temp->lt;
						    newnode->right=temp;
							temp->left=newnode;
						    temp->lt=0;
						    break;
					 }
				  else {
					temp=temp->left;
				  }
				  		
			   }
			   else if(newnode->data >=temp->data)
			   {
			   	if(temp->rt==1)
		   	         {
						    newnode->right=temp->right;
							nnode->rt=temp->rt;
						    newnode->rt=temp->rt;
						    newnode->left=temp;
   						    temp->right=newnode;
							temp->rt=0;
						    break;
					 }
				  else {
					 temp=temp->right;	
				  }
			}
			}
		   	   
		   }
		   
		}
		while(1);
	}
	
	void inorder()
	{
	Node *temp=root;
	int flag=1;
		do
		{
		
		while (temp->lt!=1 && flag==1)
		{
			temp=temp->left;
		}
		cout<<temp->data<<"\t";
		
		if(temp->rt==0)
			flag=1;
		else
			flag=0;
		
		temp=temp->right;
	
		}
		while(temp!=dummy);
	}
void preorder()
    {
        Node* temp=root;
        
        do{
            while(temp->lt!=1)
            {
            	cout<<temp->data<<"\t";
            	temp=temp->left;
			}
			if(temp->lt==1)
			{
			
			cout<<temp->data<<"\t";
			
			if(temp->rt==0)
			{
				temp=temp->right;
			}
			else
			{
				while(temp->rt==1 &&temp!=dummy )
				{
					temp=temp->right;
				}
				
				temp=temp->right;
			}
        }
        }while(temp!=dummy);
    }
	Node *getRoot()
	{
		return root;
	}
};

main()
{
	TBTree gt,gtc,gtm;
	Node *rt;
	gt.create();
	
	rt=gt.getRoot();
	cout<<"\nInorder : ";
	gt.inorder();
	cout<<"\nPreorder : ";
	gt.preorder();
}

