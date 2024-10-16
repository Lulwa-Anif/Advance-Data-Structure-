#include<iostream>
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
class graph {
    public:
int g[10][10];
int sv,ev,vertex, i, j, edge,op,cost;
int visit[10];

    graph(){
        cout<<"enter the number of vertex";
        cin>>vertex;
         for(i=0;i<vertex;i++){
            for(j=0;j<vertex;j++){
                  g[i][j]=0;
            }                 
            }
    }
    void create(){
        cout<<"enter the number of edges";
        cin>>edge;
    
        cout<<"1. undirected unweighted\n 2. directed unweighted\n3. undirected weighted\n 4. directed weighted\n";
        cin>>op;
        for(int k=0;k<edge;k++){
            cout<<"enter the starting vertex and ending vertex :"<<endl;
            cin>>sv>>ev;
            if(op==1){
                g[sv][ev]=1;
                g[ev][sv]=1;
            }
            if(op==2){
                g[sv][ev]=1;
            }
            if(op==3){
                cout<<"enter the weight of the graph";
                cin>>cost;
                g[sv][ev]=1;
                g[ev][sv]=1;
            }
            if(op==4){
                cout<<"enter the weight of the graph";
                cin>>cost;
                g[sv][ev]=1;
        }
    }
    }
void display(){
    for(i=0;i<vertex;i++){
        
        for(j=0;j<vertex;j++){
            cout<<g[i][j];
            cout<<"\t";
        }
        cout<<endl;
    }
}
void initvisit(){
    
    for(int i=0;i<vertex;i++){
         visit[i]=0;
    }
}
void DFS(int v){
visit[v]=1;
cout<<v<<"\t";
for(int i=0;i<vertex;i++){
if(visit[i]==0 && g[v][i]!=0) {
    DFS(i);
}
}
}

void BFS(int v){
    Q q;
    q.enq(v);
    visit[v]=1;
    while(! q.isempty()){
        v=q.deq();
        cout<<v<<"\t";

    for(int i=0;i<vertex;i++){
        if(visit[i]==0 && g[v][i]!=0) {
            q.enq(i);
            visit[i]=1;
        }
    }
}
}
void indegree(){
    
for(i=0;i<vertex;i++){

    int count=0;

    for(j=0;j<vertex;j++){

        if( g[j][i] != 0 ){
            count++;
        }
    }
    indg[i]=count;

} 
}
void AOV(){
    int indg[10], pos=0;
    int min,c=0;
min=indg[0];
do{

for(int i=1;i<vertex;i++){
    if(indg[i] < min ) {
        min=indg[i];
        pos=i;
    }
}
cout<<pos<<"\t";
cout<<min<<endl;

for(int i=0;i<vertex;i++){
    for(int j=0;j<vertex;j++){
        g[pos][j] = 0;
    }
    
}
indegree();
c++;
}while(c<vertex);
}
};
int main(){
graph g;
g.create();
g.AOV();
// g.display();
// g.initvisit();
// cout<<"DFS : "<<endl;
// g.DFS(0);
// cout<<"BFS : "<<endl;
// g.BFS(0);
}