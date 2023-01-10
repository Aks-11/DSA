#include<iostream>
using namespace std;

class stack
{
    public:
        int n=9,top=-1;
        int stac[100];

    void push(int ele);
    int pop();
    void display();


  
    
};

void stack::push(int ele)
{
    if(top==n) cout<<"\nStack is full\n"<<endl;

    else
    {
         
        top++;
        stac[top]=ele;
        
        
    }
}

int stack::pop()
{
    if(top==-1){
         
         return '\0';
    }
    else{
        char val=stac[top];
        
        stac[top]='\0';
        top--;
        return val;
    }
}

void stack::display()
{
    cout<<"\nThe elements of stack are \n";
    for(int i=0;i<=top;i++)
    {
        cout<<stac[i]<<endl;
        
    }
}



class queue
{
    int que[10],front=-1,rear=-1,sze=9;
    public:
    void enqueue(int ele);
    int dequeue();
   

};

void queue::enqueue(int ele)
{
    if( front==rear+1 || (rear==sze && front==0))
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

        else if(rear == sze)
        {
            rear-=sze;
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
        if(front==rear)
        {
            ele=que[front];
            que[front]='\0';
            front=rear=-1;
        }
        else if(front==sze)
        {
            ele=que[front];
            que[front]='\0';
            front-=sze;

        }
        else
        {
            ele=que[front];
            que[front]='\0';
            front++;
        }
        return ele;
    }
}

int main()
{
    stack obj;
    int opt=0;
    while(opt!=5)
    {   

        cout<<"\n\nSelec 1 option"<<endl;
        cout<<"1)Push \n2)Pop \n3)Reverse \n4)Display \n5)Exit"<<endl;
    cin>>opt;
    switch(opt)
    {
        case 1:
        { 
            int ele;
            cout<<"Enter the element to push in stack "<<endl;
            cin>>ele;
            obj.push(ele);
            break;
        }
            
        case 2:
        {
            int flag=obj.pop();
            cout<<flag<<endl;
            break;
        }
        case 3:
        {   obj.display();
            queue que;
            int ele=obj.pop();
            while(ele!='\0')
            {
                que.enqueue(ele);
                ele=obj.pop();
            }
            
            ele=que.dequeue();
            while(ele!=-1)
            {
                obj.push(ele);
                ele=que.dequeue();
            }
            
            cout<<"Reversed Stack: "<<endl;
            obj.display();
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
