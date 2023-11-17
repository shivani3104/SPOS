#include<iostream>
using namespace std;

int counter =0;

void intialization(int *p,int *a,int *b,int *pr,int size)
{
    int arr=0,bru=0,prio=0;
    for(int i=0;i<size;i++)
    {
        cout<<"enter the arrival time ,brust time and priority of process"<<i+1<<":"<<endl;
        cin>> arr >> bru >> prio;
        
        p[i]=i+1;
        a[i]=arr;
        b[i]=bru;
        pr[i]=prio;
    }
}

void swap(int *a,int*b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void swapbypriority(int *p,int *a,int *b,int *pr,int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(&a[j],&a[j+1]);
                swap(&b[j],&b[j+1]);
                swap(&p[j],&p[j+1]);
                swap(&pr[j],&pr[j+1]);
            }
        }
    }
}

void execution(int *p,int *a,int *b,int *pr,int size)
{
    int tat=0, wt=0;
    float avg_tat=0,avg_wt=0;
    
    cout<<"gnatt chart"<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<"|p"<<p[i]<<" ";
        cout<<"\n";
    }
    
    for(int i=0;i<size;i++)
    {
        cout<<"|p"<<p[i]<<" ";
        counter+=b[i];
        tat=counter-a[i];
        wt=tat-b[i];
        avg_tat+=tat;
        avg_wt+=wt;
        
        cout<<p[i]<<"\t\t"<<a[i]<<"\t\t"<<b[i]<<"\t\t"<<counter<<"\t\t"<<tat<<"\t\t"<<wt<<"\t\t"<<pr[i]<<endl;
        
    }
    cout<<"average tat : "<<avg_tat/size<<endl;
    cout<<"average wt : "<<avg_wt/size<<endl;
    
        
}

int main()
{
    int process[20];
    int arrival[30];
    int brust[20];
    int priority[20];
    int size;
    
    cout<<"Enter the size "<<endl;
    cin>>size;
    
    intialization(process,arrival,brust,priority,size);
    swapbypriority(process,arrival,brust,priority,size);
    execution(process,arrival,brust,priority,size);
}