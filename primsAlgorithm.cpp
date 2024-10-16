#include<iostream>
using namespace std;
class graph {
    public:
    int vertex,i,j,g[10][10],edges,k,op,sv,ev,w;
    int dis[10],visit[10],dfrom[10],total=0,cnt=0,vv;
graph(){
    
    cout<<"enter the vertex";
    cin>>vertex;
    for(i=0;i<=vertex;i++){
        for(j=0;j<=vertex;j++){
            g[i][j]=0;
        }
    }
    
}
void createGraph(){
    cout<<"enter the number of edges";
    cin>>edges;
     cout<<"\n1.undirected graph unweighted \n2.directed unweighted graph\n3.undirected weighted graph\n4.directed weighted graph\n";
        cin>>op;
    for(k=0;k<edges;k++){
       
        cout<<"enter start and end vertex";
        cin>>sv>>ev;
        if(op==1){
            g[sv][ev]=1;
            g[ev][sv]=1;
        }
        if(op==2){
            g[sv][ev]=1;
        }
        if(op==3){
            cout<<"enter the weight of vertex "<<k;
            cin>>w;
            g[sv][ev]=w;
            g[ev][sv]=w;
        }
        if(op==4){
            cout<<"enter the weight of vertex "<<k;
            cin>>w;
            g[sv][ev]=w;
          
        }

    }
    }
void display(){
    for(i=0;i<vertex;i++){
        for(j=0;j<vertex;j++){
            cout<<g[i][j]<<"\t";
        }
        cout<<"\n";
    }
}
void prims(){
for(i=0;i<vertex;i++){
    dis[i]=999;
    visit[i]=0;
    dfrom[i]=0;
}
sv=0;
do {
visit[sv]=1;
for(i=0;i<vertex;i++){
   if(g[sv][i]!=0 && visit[i]==0){
    if(dis[i]>g[sv][i]) {
        
        dis[i]=g[sv][i];
        dfrom[i]=sv;
    }
   }
}
int min=999,vv=0;
for(i=0;i<vertex;i++){
    if(dis[i]<min && visit[i]==0) {
        min=dis[i];
        vv=i;
    }
}
cout<<"min cost : "<<min;
cout<<"\t"<<vv;
total=total+min;
sv=vv;
cnt++;
} while(cnt<vertex);

cout<<"\ntotal : "<<total;

}
};
int main(){
graph g;
g.createGraph();
g.display();
g.prims();

}