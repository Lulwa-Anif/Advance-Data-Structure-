#include <iostream>
using namespace std;
class Q
{
public:
int q[10];
int f,r;
Q()
{
f=0;
r=-1;
}
void enq(int n)
{
r++;
q[r]=n;
}
int deq()
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

   int g[10][10],vertex,edges,dis[10],dfrom[10],sv,visit[10],total,cnt;

public:
Graph()
{
vertex=10;
for(int i=0;i<vertex;i++)
 {
  for(int j=0;j<vertex;j++)
   g[i][j]=0;
  }

}


void initvisit()
{
for(int i=0;i<vertex;i++)
{
visit[i]=0;
}
}

void DFS(int v)
{
cout<<v<<"\t";
visit[v]=1;
for(int i=0;i<vertex;i++)
{
if(g[v][i]!=0 && visit[i]==0)
  DFS(i);
}
}


Graph(int v)
{
vertex=v;
int i,j;
for(i=0;i<vertex;i++)
 {
  for(j=0;j<vertex;j++)
   g[i][j]=0;
 }
  }

void creategraph()
{
 int sv,ev,k,w, type;
 cout<<"\nEnter a vertex";
   cin>>vertex;
   cout<<"\nEnter a Edges";
   cin>>edges;
   cout<<"\nMENU\n1.Undirected UnWe\n2.Directed UnWe\n3.Undirected Weig\n4.Directed Weigh\nEnter a type of Graph";
   cin>>type;
   for(k=1;k<=edges;k++)
   {
      cout<<"\nEnter a start vertex and end vertex of Edge "<<k;
      cin>>sv>>ev;
      if(type==1)
{

      g[sv][ev]=1;
      g[ev][sv]=1;
}
else if(type==2)
{
g[sv][ev]=1;
     
}
else if(type==3)
{
cout<<"Enter a Weight for edge  "<<k;
cin>>w;
g[sv][ev]=w;
g[ev][sv]=w;
     
}
else if(type==4)
{
cout<<"Enter a Weight for edge  "<<k;
cin>>w;
g[sv][ev]=w;
}
}
}

void showgraph()
{
  int i,j;
  for(i=0;i<vertex;i++)
 {
  printf("\n");
  for(j=0;j<vertex;j++)
   printf("%d\t",g[i][j]);
 }
}
void BFS(int v)
{
Q q1;
q1.enq(v);
visit[v]=1;

while(!q1.isempty())
{

v=q1.deq();
cout<<v<<",\t";
for(int i=0;i<vertex;i++)
{
if(g[v][i]!=0 && visit[i]==0)
  {
  q1.enq(i);
  visit[i]=1;
  }
}
}
}
};
int main() {
    Graph g;
    g.creategraph();
    g.showgraph();
    g.initvisit();
    cout<<"\nDFS : ";
    g.DFS(0);
    g.initvisit();
    cout<<"\nBFS : ";
    g.BFS(0);
    
return 0;
}
