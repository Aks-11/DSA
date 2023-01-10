#include<iostream>
using namespace std;

class queue
{
    int que[100],front=-1,rear=-1,sze=99;
    public:
    void enqueue(int ele);
    int dequeue();
    void peek();
    void display();

};

void queue::enqueue(int ele)
{
    if( rear==sze-1)
    {
        cout<<"The queue is full"<<endl;
    }
    else
    {
        if(rear==-1 && front==-1)
        {
            front++;
            rear++;
            que[rear]=ele;
        }

       
        else
        {
            rear++;
            que[rear]=ele;
        }
    }
}

int queue::dequeue()
{
    if(front==-1 && rear==-1)
    {
        return -1;
    }
    else
    {
        int ele;
        
        
            ele=que[front];
            que[front]='\0';
            front++;
        
        return ele;
    }
}
void queue::peek()
{
    cout<<"Front is: "<<que[front]<<endl;
    cout<<"Rear is: "<<que[rear]<<endl;
}
void queue::display()
{
    cout<<"!<==============================================>!"<<endl;
    int trav=front;
    if(front==-1 && rear==-1)
        cout<<"Queue is empty"<<endl;
    else if(front==rear)
        cout<<que[front]<<endl;
    else
    {
        while(trav!=rear+1)
        {
            
            cout<<que[trav]<<endl;
            trav++;
        }
    }
}

int main()
{
    queue obj;
    int opt=0;
    while(opt!=5)
    {   

        cout<<"\n\nSelec 1 option"<<endl;
        cout<<"1)Enqueue \n2)Dequeue \n3)Peek \n4)Display \n5)Exit"<<endl;
    cin>>opt;
    switch(opt)
    {
        case 1:
        { 
            int ele;
            cout<<"Enter the element to enqueue in queue "<<endl;
            cin>>ele;
            obj.enqueue(ele);
            break;
        }
            
        case 2:
        {
            int flag;
            flag=obj.dequeue();
            if(flag==-1)
                cout<<"Queue is empty"<<endl;
            else
                cout<<flag<<" is dequeued "<<endl;
            break;
        }
        case 3:
        {
            obj.peek();
            break;
        }
        case 4:
        {
            obj.display();
            break;
        }
        case 5:
        {
            cout<<"Exiting"<<endl;
            break;
        }
        default:
        {
            cout<<"Invalid Input"<<endl;
            break;
        }
    }
    }
}