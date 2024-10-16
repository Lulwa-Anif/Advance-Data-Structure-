#include<iostream>
using namespace std;
class graph {
    public:
    int vertex,i,j,g[10][10],edges,k,op,sv,ev,w;
    int pos=0,indg[10];

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
    void indegree(){
        int c;
    for(i=0;i<=vertex;i++){
      c=0;
            for(j=0;j<=vertex;j++){
                 
                 if(g[j][i]!=0){
                  c++;
}

            }
            indg[i]=c;
    }
    // for(i=0;i<vertex;i++){
        
    //     cout<<indg[i];
    // }

}
void AOV(){
int count=0;
int min=indg[0];

do {

for(i=0;i<vertex;i++){
if(min>indg[i]){

min=indg[i];
pos=i;

}
}
cout<<min;
cout<<"\t"<<pos<<"\n";

for(i=0;i<vertex;i++){
        for(j=0;j<vertex;j++){

           g[pos][j]=0;
      
        }        
}
indegree();
count++;
}while(count<vertex);
    
}
void display(){

    for(i=0;i<vertex;i++){
        for(j=0;j<vertex;j++){
            cout<<g[i][j]<<"\t";
        }
        cout<<"\n";
    }
}

};
int main(){
graph g;
g.createGraph();
g.display();
g.indegree();
g.AOV();
}
