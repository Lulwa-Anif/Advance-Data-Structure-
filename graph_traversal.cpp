#include<iostream>
using namespace std;

class Q
{
	int q[10];
	int f,r;
	public:
		Q()
		{
			f=0;
			r=-1;
		}
		void enque(int n)
		{
			r++;
			q[r]=n;
		}
		int deque()
		{
			int n=q[f];
			f++;
			return n;
		}
		int isempty()
		{
			if(f==r+1)
			   return 1;
			else
			  return 0;
		}
};
class Graph
{

   int G[10][10],vertex,edges,visit[10];

public:
	void initvisit()
	{
		for(int i=0;i<vertex;i++)
		{
			visit[i]=0;
		}
	}
	
	Graph()
	{
		vertex=10;
		for(int i=0;i<vertex;i++)
		  {
	   		for(int j=0;j<vertex;j++)
	  		  G[i][j]=0;
	  		}
		
	}
	Graph(int v)
	{
	vertex=v;
	int i,j;
	for(i=0;i<vertex;i++)
	  {
	   for(j=0;j<vertex;j++)
	  	  G[i][j]=0;
	  }
  }

void creategraph()
{
    char sc,ec;
	  int k,w,sv,ev ,type;
   cout<<"\nEnter a Edges";
   cin>>edges;
   cout<<"\nMENU\n1.Undirected UnWe\n2.Directed UnWe\n3.Undirected Weig\n4.Directed Weigh\nEnter a type of Graph";
   cin>>type;
   for(k=1;k<=edges;k++)
   {
   	   cout<<"\nEnter a start vertex and end vertex of Edge "<<k;
   	   cin>>sc>>ec;
   	   sv=sc-65;
   	   ev=ec-65;
   	   if(type==1)
	{
	
   	   G[sv][ev]=1;
   	   G[ev][sv]=1;
	}
	else if(type==2)
	{
	 G[sv][ev]=1;
   	  	
	}
	else if(type==3)
	{
		cout<<"Enter a Weight for edge  "<<k;
		cin>>w;
	 G[sv][ev]=w;
	 G[ev][sv]=w;
   	  	
	}
	else if(type==4)
	{
		cout<<"Enter a Weight for edge  "<<k;
		cin>>w;
	 G[sv][ev]=w;
   	  	
	}
	
	
   }
   
}
   
   	


void showgraph()
{
  int i,j;
  		for(i=0;i<vertex;i++)
		   cout<<"\t"<<(char)(65+i);
		   
		   
  		for(i=0;i<vertex;i++)
	  {
	  	cout<<"\n"<<(char)(65+i);
	   for(j=0;j<vertex;j++)
	  	  cout<<"\t"<<G[i][j];
	  }
}

void DFS(char sv)
{
	int s;
   cout<<"\t"<<sv;
   	s=sv-65;
   	visit[s]=1;
   	for(int i=0;i<vertex;i++)
   	{
   		if(G[s][i]!=0 && visit[i]==0)
   		    DFS((char)(i+65));
    }
}
void BFS(char sv)
{
	int s;
  initvisit();	
  Q q1;
  s=65-sv;
  q1.enque(s);
  visit[s]=1;
  while(!q1.isempty())
	{

  s=q1.deque();
  cout<<"\t"<<(char)(s+65);
  	for(int i=0;i<vertex;i++)
   	{
   		if(G[s][i]!=0 && visit[i]==0)
   	       {
   	         q1.enque(i);
			 visit[i]=1;	
		   }
   }
	}
	}	
};
main()
{
	int v;
	cout<<"\nEneter a vertex";
	cin>>v;
  Graph g(v);
  g.creategraph();
  g.showgraph();
  g.initvisit();
  char sv;
  cout<<"\nEnter start vertex for dFS Traversal";
  cin>>sv;
  cout<<"\nDFS Traversal : ";
  g.DFS(sv);
  cout<<"\nEnter start vertex for BFS Traversal";
  cin>>sv;
  g.BFS(sv);
  
}
