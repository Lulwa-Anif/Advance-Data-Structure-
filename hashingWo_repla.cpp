#include<iostream>
using namespace std;
class hashing {
    public:
int hash[10][2];
hashing()
{
    for(int i=0;i<10;i++){
        hash[i][0]=0;
        hash[i][1]=-1;
    }
    
}
void insert();
void display();
};
void hashing :: insert() {
    int hashkey,prevkey,data;

    cout<<"enter data";
    for(int i=0;i<10;i++){
        cin>>data;
        hashkey=data%10;
        if(hash[hashkey][0]==0){
            hash[hashkey][0]=data;
        }
        else {
            prevkey=hashkey;
            while(hash[hashkey][0]!=0) { 
                hashkey=(hashkey+1)%10;
            }

            while(hash[prevkey][1]!=-1) 
                prevkey=hash[prevkey][1];
            

            hash[hashkey][0]=data;
            hash[prevkey][1]=hashkey;
        }
    }
}
void hashing :: display(){
for(int i=0;i<10;i++){

cout<<i<<"\t"<<hash[i][0]<<"\t"<<hash[i][1]<<"\n";
}
}
int main(){
    hashing h;
    h.insert();
    h.display();
}