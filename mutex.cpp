#include<iostream>
using namespace std;

class synronization
{
    public:
        int mutex=1;
        int full=0;
        int empty=5;
        int a[5];
    
    void wait(int &x)
    {
        if(x>0)
        {
            x--;
        }
    }
    
    void signal(int &x)
    {
        x++;
    }
    
    void producer()
    {
        cout<<"Empty :"<<empty<<"Full :"<<full<<"Mutex"<<mutex<<endl;
        if(empty!=0 && mutex==1)
        {
            wait(empty);
            wait(mutex);
            cout<<"Enter data to be produced :"<<endl;
            cin>>a[full];
            cout<<"Enter data to be produced :"<<a[full]<<endl;
            signal(full);
            signal(mutex);
            
            cout<<"Empty :"<<empty<<"Full :"<<full<<"Mutex"<<mutex<<endl;
            
        }
    }
    
    void consumer()
    {
        cout<<"Empty :"<<empty<<"Full :"<<full<<"Mutex"<<mutex<<endl;
        if(full!=0 && mutex==1)
        {
            wait(full);
            wait(mutex);
            cout<<"Enter data to be consume :"<<a[full]<<endl;
            signal(empty);
            signal(mutex);
            
            cout<<"Empty :"<<empty<<"Full :"<<full<<"Mutex"<<mutex<<endl;
            
        }
    }
    
    void output()
    {
        cout<<"remaining memory is: "<<endl;
        cout<<"Empty :"<<empty<<"Full :"<<full<<"Mutex :"<<mutex<<endl;
    }
};
int main()
{
    int ch;
    synronization s;
    do
    {
        cout<<"Main Menu"<<endl;
        cout<<"1.Producer"<<endl;
        cout<<"2.consumer"<<endl;
        cout<<"3.Exit"<<endl;
        cout<<"Enter your choice: "<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
                s.producer();
                break;
            case 2:
                s.consumer();
                break;
            case 3:
                s.output();
                break;
            default:
                break;
            }
        
    }while(ch!=3);
    return 0;
}

