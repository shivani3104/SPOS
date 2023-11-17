#include<iostream>
using namespace std;

void printresult(int n,int procsize[],int allocation[])
{
	cout<<"\nProcess No. \t Process Size \t Block No. \t Status \n";
	for(int i=0;i<n;i++)
	{
		cout<<" "<<(i+1)<<"\t\t\t"<<procsize[i]<<"\t";
		if(allocation[i]!=-1)
			cout<<"\t"<<(allocation[i]+1)<<"\t Allocated";
		else
			cout<<"\t- "<<"\t Not allocated";
		cout<<endl;
	}
}

// m=number of blocks
// procsize=an array of process size

void firstfit(int blocksize[],int m,int procsize[],int n)
{
	int allocation[n];
	for(int i=0;i<n;i++){
		allocation[i]=-1;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(blocksize[j]>=procsize[i])
			{
				allocation[i]=j;
				blocksize[j]=0;
				break;
			}
		}
	}
	printresult(n,procsize,allocation);
}
void nextfit(int blocksize[],int m,int procsize[],int n)
{
	int allocation[n];
	for(int i=0;i<n;i++){
		allocation[i]=-1;
	}
	int t=m-1,j=0;
	for(int i=0;i<n;i++)
	{
		while(j<m)
		{
			if(blocksize[j]>=procsize[i])
			{
				allocation[i]=j;
				blocksize[j]=0;
				t=(j-1)%m;
				break;
			}
			if(t==j){
				t=(j-1)%m;
				break;
			}
			j=(j+1)%m;
		}
	}
	printresult(n,procsize,allocation);
}
void bestfit(int blocksize[],int m,int procsize[],int n)
{
	int allocation[n];
	for(int i=0;i<n;i++){
		allocation[i]=-1;
	}
	for(int i=0;i<n;i++)
	{
		int bstidx=-1;
		for(int j=0;j<m;j++)
		{
			if(blocksize[j]>=procsize[i])
			{
				if(bstidx==-1)
					bstidx=j;
					
				else if(blocksize[bstidx] > blocksize[j])
					bstidx=j;
			}
		}
		if(bstidx!=-1)
		{
			allocation[i]=bstidx;
			blocksize[bstidx]=0;
		}
	}
	
	printresult(n,procsize,allocation);
}
void worstfit(int blocksize[],int m,int procsize[],int n)
{
	int allocation[n];
	for(int i=0;i<n;i++){
		allocation[i]=-1;
	}
	for(int i=0;i<n;i++)
	{
		int wstidx=-1;
		for(int j=0;j<m;j++)
		{
			if(blocksize[j]>=procsize[i])
			{
				if(wstidx==-1)
					wstidx=j;
				else if(blocksize[wstidx] < blocksize[j])
					wstidx=j;
			}
		}
		if(wstidx!=-1)
		{
			allocation[i]=wstidx;
			blocksize[wstidx]=0;
		}
	}
	printresult(n,procsize,allocation);
}

int main()
{

	int m=5,n=4;
	
	//firstfit(blocksize,m,procsize,n);
	//bestfit(blocksize,m,procsize,n);
	
	int ch;
	do
	{
		cout<<"\n____________________________________";
		cout<<"\n\t[1] First Fit\n\t[2] Best Fit\n\t[3] Next Fit\n\t[4] Worst Fit";
		cout<<"\n____________________________________";
		cout<<"\nEnter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:{
				int bsize1[5]={100,500,200,300,600};
				int psize1[4]={212,417,112,426};
				firstfit(bsize1,5,psize1,4);	
				break;
			}
				
			case 2:{
				int bsize1[5]={100,500,200,300,600};
				int psize1[4]={212,417,112,426};
				bestfit(bsize1,5,psize1,4);	
				break;
			}
			
			case 3:{
				int bsize1[5]={100,500,200,300,600};
				int psize1[4]={212,417,112,426};
				nextfit(bsize1,5,psize1,4);	
				break;
			}
			
			case 4:{
				int bsize1[5]={100,500,200,300,600};
				int psize1[4]={212,417,112,426};
				worstfit(bsize1,5,psize1,4);	
				break;
			}
		}
		cout<<"\n____________________________________";
		cout<<"\nPress 1 to continue : ";
		cin>>ch;
	}while(ch==1);
	return 0;
}

