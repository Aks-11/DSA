#ifndef imprtinfitopost
#define imprtinfitopost

int chkparen(char[]);
void intopo(char[]);
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
    if(top==n){}

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
            {   
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
            {   
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
            {   
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

void intopo(char arr[100])
{
    stack obj;
    char str[100];
    int j=0,brac=0;
    for(int i=0;arr[i]!='\0';i++)
    {
        switch (arr[i])
        {
            case 'A'...'Z':
            case 'a'...'z':
            case '0'...'9':
            {
                str[j]=arr[i];
                j++;
                

                
                break;
            }
            case '(':
            case '[':
            case '{':
            {
                obj.push(arr[i]);
                brac++;
                break;
            }
            case ')':
            case ']':
            case '}':
            {
                if(arr[i]=='}')
                {
                    
                    while(obj.peek()!='{')
                    {
                        
                        str[j]=obj.pop();
                        j++;
                    }
                    obj.pop();
                    brac--;
                }
                if(arr[i]==')')
                {
                    while(obj.peek()!='(')
                    {
                        str[j]=obj.pop();
                        
                        j++;
                    }
                    obj.pop();
                    brac--;
                }
                if(arr[i]==']')
                {
                    while(obj.peek()!='[')
                    {
                         str[j]=obj.pop();
                       
                        j++;
                    }
                    obj.pop();
                    brac--;
                }
                break;
            }

            case ('+'):
            {
                if(brac==0)
                {
                    while(obj.peek()!='\0')
                    {
                        str[j]=obj.pop();
                        j++;

                    }
                    obj.push('+');
                }
                else
                {
                    
                    while(obj.peek()!='(' && obj.peek()!='[' && obj.peek()!='{')
                    {
                        str[j]=obj.pop();
                        j++;
                    }
                    obj.push('+');
                }
                
                break;
            }

            case('-'):
            {
                if(brac==0)
                {
                    while(obj.peek()!='\0')
                    {
                        str[j]=obj.pop();
                        j++;

                    }
                    obj.push('-');
                }
                else
                {
               
                    while(obj.peek()!='(' && obj.peek()!='[' && obj.peek()!='{')
                    {
                        str[j]=obj.pop();
                        j++;
                    }
                    obj.push('-');
                }
                break;
            }

            case('/'):
            {
                
                if(obj.peek()=='-'|| obj.peek()=='+'||obj.peek()=='[' || obj.peek()=='{'|| obj.peek()=='('||obj.peek()=='\0')
                {
                    obj.push('/');
                }
                
                else 
                {                
                    while(obj.peek()=='*' || obj.peek()=='/')
                    {
                        if(obj.peek()=='[' || obj.peek()=='{'|| obj.peek()=='('||obj.peek()=='\0')
                            break;
                        str[j]=obj.pop();
                        j++;
                    }
                    obj.push('/');
                }
                break;
            }
            
            case('*'):
            {
                if(obj.peek()=='-'|| obj.peek()=='+'||obj.peek()=='[' || obj.peek()=='{'|| obj.peek()=='('||obj.peek()=='\0')
                {
                    obj.push('*');
                }

               
                else 
                {
                    
                   
                    while(obj.peek()=='*' || obj.peek()=='/')
                    {
                        if(obj.peek()=='[' || obj.peek()=='{'|| obj.peek()=='('||obj.peek()=='\0')
                            break;
                        str[j]=obj.pop();
                        j++;
                    }
                    obj.push('*');
                    
                }
                break;
            }
        }       
    }
    while(obj.peek()!='\0')
    {
        str[j]=obj.pop();
        j++;
    }
    str[j]='\0';
    
    string str1=str;
    int i=0;
    while(str[i]!='\0')
    {
        arr[i]=str[i];
        i++;
    }
    arr[i]='\0';
    
}
#endif