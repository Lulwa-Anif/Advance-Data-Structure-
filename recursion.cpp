#include<iostream>
using namespace std;
int factorial(int n){
    int fact;
    if(n==0){
        return n;
    }
    fact += factorial(n*(n-1));
  
}
int main(){
    
    factorial(5);
    cout<<fact;
}