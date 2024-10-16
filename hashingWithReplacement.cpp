#include<iostream>
using namespace std;

class Hashing
{
   int ht[10][2];
   public:
   	Hashing()
   	{
   		for(int i=0;i<10;i++)
   		{
   			ht[i][0]=0;
   			ht[i][1]=-1;
		   }
	   }
   	int hashkey(int no)
   	{
	  return no%10;
	}
	void insert(int no);
	bool search(int no);
	void showtable();
};
	void Hashing:: insert(int no)
	{
		int k=hashkey(no);
		
		int c=k;
		if(ht[k][0]==0)
		   ht[k][0]=no;
		else
		{
			while(ht[k][0]!=0 ) //empty place
			  k=(k+1)%10;
			
			
			
			while(ht[c][1]!=-1) //to maintain key 
			{
				c=ht[c][1];
			  }  
			ht[k][0]=no; //assign data @ place
			ht[c][1]=k; //assign key 
			
			
		}
		
	}
	void Hashing:: showtable()
	{
		for(int i=0;i<=9;i++)
		   cout<<"\n"<<i<<"\t"<<ht[i][0]<<"\t"<<ht[i][1];
	}
	bool Hashing :: search(int no)
	{
		
	}

main()
{
	int x;
	Hashing h;
	for(int i=1;i<=10;i++)
	  {
	  cin>>x;
		h.insert(x);
		}
	h.showtable();
}
	
	
	
	
	
