#include<iostream>
using namespace std;
class graph {
    public:
graph(){
     for(i=0;i<v;i++){
        for(j=0;j<v;j++){
          g[i][j]=0;
        }
    }
}
 cout<<"enter the no. of vertex";
    cin>>v;
    for(i=0;i<v;i++){
        for(j=0;j<v;j++){
           cin>>g[i][j];
        }
    }
void create(){

    cout<<"enter the no. of edges";
    cin>>e;
    cout<<"enter the cost(time)";
    cin>>time;
    for(i=0;i<e;i++){
        cout<<"enter the source";
        cin>>source;
        cout<<"enter the destination";
        cin>>dest;
        g[source][dest]=time;
    }
}
void display(){
   
        cout << "\nCollege route representation using adjacency matrix:" << endl;
        for (int i = 0; i < v; i++)
            cout << "\t" << city[i];
        for (int i = 0; i < v; i++) {
            cout << "\n" << city[i];
            for (int j = 0; j < v; j++) {
                cout << "\t" << graph[i][j];
            }
        }
        cout << endl;
}

void connected(){
    cout<"enter the source city";
    cin>>s;
    cout<<"enter the destination city";
    cin>>d;
    for(i=0;i<vertex;i++){
        for(j=0;j<vertex;j++){
           if(g[i][j] != 0){
            cout<<"route are present";
           }
           else {
            cout<<"route are not present";
           }
        }
    }
    
}
};
int main(){
    int op,v,i,j,g[10][10],e;
    string city[10],s,d,source,dest;
    graph g;
for(i=0;i<v;i++){
    cin>>city[i];
}

    switch(op){
        case 1:

        break;
        case 2:

        break;
        case 3:

        break;
        case 4:

        break;
    }
}