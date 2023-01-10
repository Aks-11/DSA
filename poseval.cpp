#include<iostream>
using namespace std;
int post(char[]);
class stack
{
    public:
        int n=9,top=-1;
        int stac[100];

    void push(int ele);
    int pop();
    int peek();
  
    
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

int stack::peek()
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
    int val=post(arr);
    cout<<"The evaluation of Postfix= "<<val<<endl;
}
int post(char arr[100])
{
    stack obj;
    int val;
    for(int i=0;arr[i]!='\0';i++)
    {
        switch (arr[i])
        {
            
            case '0'...'9':
            {
                obj.push(int(arr[i])-48);
                break;
            }

            case '+':
            {
                int num1=obj.pop();
                int num2=obj.pop();
                val=num1+num2;
               
                obj.push(val);
                break;
            }
            case '-':
            {
               
                int num2=obj.pop();
                 int num1=obj.pop();
                val=num1-num2;
                obj.push(val);
                break;
            }
            case '*':
            {
                int num1=obj.pop();
                int num2=obj.pop();
                val=num1*num2;
                obj.push(val);
                break;
            }
            case '/':
            {
                
                int num2=int(obj.pop());
                 int num1=obj.pop();
                val=num1/num2;
                obj.push(val);
                break;
            }
            default:
            break;
        }
    }
   
    return obj.pop();
}