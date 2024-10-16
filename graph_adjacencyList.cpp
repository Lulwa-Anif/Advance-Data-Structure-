#include<iostream>
using namespace std;
class Node
{
	int data;
	//int weight;
	Node *next;
public:
	Node()
	{
		data=0;
		next=NULL;
	}
	friend class GraphALL;
};
class GraphALL
{
	Node* da[10];
	int vertex,edges;  
	int visit[10];
	public:
		GraphALL(int v,int e)
		{
			vertex=v;
			edges=e;
			
			for(int i=0;i<vertex;i++)
			{
				da[i]=new Node;
				da[i]->data=i;
			
			}
		}
		void initvisit()
		{
			for(int i=0;i<vertex;i++)
			{
				visit[i]=0;
			}
		}
		void create()
		{
			int sv,ev;
			Node *newnode,*temp;
			for(int i=0;i<edges;i++)
			{
				cout<<"\nEnter start vertex & end vertex";
				cin>>sv>>ev;
				newnode=new Node;
				newnode->data=ev;
				for(temp=da[sv];temp->next!=NULL;temp=temp->next);
				temp->next=newnode;
				
				
			}
		}
		void display()
		{
			Node *temp;
			for(int i=0;i<vertex;i++)
			{
				cout<<endl;
				for(temp=da[i];temp!=NULL;temp=temp->next)
					cout<<temp->data<<"->";
			}
		}
		void DFS(int v)
		{
			
				cout<<v<<"\t";
				visit[v]=1;
				for(Node *temp=da[v];temp!=NULL;temp=temp->next)
				{
				 		if(visit[temp->data]==0)
					  		DFS(temp->data);
				}
			
		}
		
	
};
main()
{
	int v,e;
	cout<<"\nEnter a Number of vertex";
	cin>>v;
	cout<<"\nEnter a Number of edges";
	cin>>e;
	GraphALL g1(v,e);
	g1.create();
	g1.display();
	g1.initvisit();
	// g1.DFS(0);
	
}
