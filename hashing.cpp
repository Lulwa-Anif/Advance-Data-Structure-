#include<iostream>
using namespace std;
class hashing {
public:
int hash[10]={0},n,j,i,k,data,hashkey;
int key;
void create() {
cout<<"enter size of data";
cin>>n;

for(j=0;j<n;j++) {
cout<<"enter data";
cin>>data;
hashkey=data%10;
if(hash[hashkey]==0){
hash[hashkey]=data;
}
else {
while(hash[hashkey]!=0) {

hashkey=(hashkey+1)%n;

}
hash[hashkey]=data;

}
}
}

void display(){
for(i=0;i<n;i++){
cout<<i<<"\t"<<hash[i]<<"\n";
}
}
void search(){
cout<<"enter key to search";
cin>>key;
for(i=0;i<n;i++){

if(hash[i]==key){
cout<<"key found at index"<<i;
}
}
}		
};
int main(){
hashing hs;
hs.create();
hs.display();
hs.search();
}
