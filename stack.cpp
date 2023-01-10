#include<iostream>
using namespace std;
void chkparen(char[], int);
class stack
{
    public:
        int stac[10],n=9,top=-1;

    void push(int ele);
    void pop();
    void peek();
    void display();
    
};

void stack::push(int ele)
{
    if(top==n) cout<<"\nStack is full\n"<<endl;

    else
    {
        cout<<"\nThe element "<<ele<<" is pushed in stack"<<endl;
        top++;
        stac[top]=ele;
        
    }
}

void stack::pop()
{
    if(top==-1) cout<<"\nStack is empty\n"<<endl;
    else{
        cout<<"\nThe element "<<stac[top]<<" is poped"<<endl;
        stac[top]='\0';
        top--;
    }
}

void stack::peek()
{
    if(top==-1) cout<<"\nThe stack is empty\n"<<endl;
    else{
        cout<<"\nThe top of stack is "<<stac[top]<<endl; 
   }

}

void stack::display()
{
    cout<<"\nThe elements of stack are \n";
    for(int i=0;i<=top;i++)
    {
        cout<<stac[i]<<endl;
        cout<<endl;
    }
}

int main()
{
    stack obj;
    while(true)
    {   int opt;

        cout<<"\n\nSelec 1 option"<<endl;
        cout<<"1)Push \n2)Pop \n3)Peek \n4)Display "<<endl;
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
            obj.pop();
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
        default:
        {
            cout<<"Invalid Input"<<endl;
            break;
        }
    }
    }
}

