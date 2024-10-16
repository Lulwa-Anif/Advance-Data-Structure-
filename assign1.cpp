#include<iostream>
using namespace std;
int a[10][10], v,time;
string city[10];
int graph(int v){

    
    cout<<"enter city name";
     for(int i=0;i<v;i++){ 
        for(int j=0;j<v;j++){
          a[i][j]=0;
        }
    }
}
int takeCity(int v){
int i;
   for(i=0;i<v;i++){
    cin>>city[i];
}
}


void display(int vertex) {
        cout << "\nCollege route representation using adjacency matrix:" << endl;
        for (int i = 0; i < vertex; i++)
            cout << "\t" << city[i];
        for (int i = 0; i < vertex; i++) {
            cout << "\n" << city[i];
            for (int j = 0; j < vertex; j++) {
                cout << "\t" << a[i][j];
            }
        }
        cout << endl;
    }
int search(string cityName){
    for(int i=0;i<v;i++){
        if(city[i]==cityName){
            return i;
        }
    }
}
int connected(int e){
    string s,d;
    int sv,ev;
    for(int i=0;i<e;i++){
    cout<<"enter the source city, destination city and time : "<<endl;
    cin>>s>>d>>time;
    sv=search(s);
    ev=search(d);
    a[sv][ev]=time;
    }
}
int check(int v){
    int flag=0;
    string c1,c2;
    cout<<"enter city ";
    cin>>c1>>c2;
    int sv=search(c1);
    int ev=search(c2);
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(a[sv][ev]!=0){
                flag=1;
            }
            
        }
    }
     if(flag==1) {    
        cout<<"\nRoute is available";
     }
    else{
            cout<<"\nRoute not available";
          }
            
}
int main(){
    int i,j,e;
cout<<"enter the no. of vertex";
cin>>v;
cout<<"enter the no. of edges";
cin>>e;
   
graph(v);
takeCity(v);
connected(e);
display(v);
check(v);
return 0;
}

//this is the code for adjacency list
/*
class GraphAdjList {
    Node* vertices[10], *nnode;
    Node* temp;

public:
    GraphAdjList(int v, int e) {
        ver = v;
        edge = e;

        for (int i = 0; i < ver; ++i) {
            vertices[i] = new Node("\0");
            vertices[i]->data = city[i];
        }
    }

    void create(string sv, string ev,float w) {
        int s = search(sv);
        int e = search(ev);

        if (s == -1 || e == -1) {
            cout << "Error: City not found!" << endl;
            return;
        }

        nnode = new Node(ev);
        nnode->next = vertices[s]->next;  
        vertices[s]->next = nnode;
        nnode->weight=w;
    }

    void display() {
        cout<<"\nPlane route representation using Adjacency List:"<<endl;
        for (int i = 0; i < ver; i++) {
            cout << city[i];
            for (temp = vertices[i]->next; temp != NULL; temp = temp->next) {
                cout << "->" << temp->data<<","<<temp->weight;
            }
            cout << endl;
        }
    }
};
*/