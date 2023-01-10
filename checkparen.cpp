#include<iostream>
using namespace std;
int chkparen(char[]);

class stack
{
    public:
        int n=9,top=-1;
        char stac[100];

    void push(char ele);
    char pop();
    char peek();
  
    
};

void stack::push(char ele)
{
    if(top==n) cout<<"\nStack is full\n"<<endl;

    else
    {
        
        top++;
        stac[top]=ele;
        
    }
}

char stack::pop()
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

char stack::peek()
{
    if(top==-1) return '\0';
    else{
        return stac[top]; 
   }

}



int main()
{
    char arr[100],  n;
    cout<<"Enter the expression"<<endl;
    cin>>arr;
    int flag;
    flag=chkparen(arr);
    if(  flag==1)
        cout<<"\nThe expression is correct"<<endl;
    else 
        cout<<"\nThe expression in incorrect"<<endl;


  
}

int chkparen(char arr[100])
{
    stack obj2;
    char opr;
    int i=0;
    while(arr[i]!='\0')
    {
        
        if(arr[i]=='[' || arr[i]=='{' || arr[i]=='(')
        {
            obj2.push(arr[i]);
            opr=arr[i];
        }
        
        else if(arr[i]==']' )
        {
            if(opr=='[')
            { obj2.pop();
                opr=obj2.peek();
            }
            else
            {   cout<<"Invalid";
                return -1;
            }

        }
        else if(arr[i]=='}')
        {
            if(opr=='{') 
            { obj2.pop();
                opr=obj2.peek();
            }
            else
            {   cout<<"Invalid";
                return -1;
            }

        }
        else if(arr[i]==')') 
        {
            if(opr=='(') 
            { obj2.pop();
                opr=obj2.peek();
            }
            else
            {   cout<<"Invalid";
                return -1;
            }

        }
        else
        {
            i++;
             continue;
        }
        i++;
    }
      
    char val=obj2.pop();
    
   
    if( val=='\0')
        return 1;
    else 
        return -1;
}

