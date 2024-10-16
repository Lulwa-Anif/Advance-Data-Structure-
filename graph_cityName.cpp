#include<iostream>
using namespace std;

string city[]={"Mumbai","Delhi","Nashik","Aurangabad","Pune","Banglore","Chennai"};

int search(string cname)
{
	for(int i=0;i<7;i++)
	{
		if(city[i]==cname)
		  return i;
	}
}
class Graph
{

   int G[10][10],vertex,edges;

public:
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
	string scv,ecv;
	int sv,ev;
	  int k,w, type;
   cout<<"\nEnter a Edges";
   cin>>edges;
   cout<<"\nMENU\n1.Undirected UnWe\n2.Directed UnWe\n3.Undirected Weig\n4.Directed Weigh\nEnter a type of Graph";
   cin>>type;
   for(k=1;k<=edges;k++)
   {
   	   cout<<"\nEnter a start vertex and end vertex of Edge "<<k;
   	   cin>>scv>>ecv;
   	   sv=search(scv);
   	   ev=search(ecv);
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
		   cout<<"\t"<<city[i];
		   
		   
  		for(i=0;i<vertex;i++)
	  {
	  	cout<<"\n"<<city[i];
	   for(j=0;j<vertex;j++)
	  	  cout<<"\t"<<G[i][j];
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
}
