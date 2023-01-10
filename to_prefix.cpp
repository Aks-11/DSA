#include<iostream>
#include<string.h>
using namespace std;
#include "imprtinfitopost.cpp"

void rev(char p[])
{
    int i=0,j=strlen(p)-1;
    char c;
    // p[0]='2';
     while(i!=j && i<j)
    {
        c=p[i];
        p[i]=p[j];
        p[j]=c;
        i++;
        j--;
    }
}

int main()
{
    char expr[100];
    cout<<"Enter a string"<<endl;
    cin>>expr;

    rev(expr);
    int i=0;
    
    while(expr[i]!='\0')
    {
        if(expr[i]=='(') expr[i]=')';
        else if(expr[i]==')') expr[i]='(';
        else if(expr[i]=='{') expr[i]='}';
        else if(expr[i]=='}') expr[i]='{';
        else if(expr[i]=='[') expr[i]=']';
        else if(expr[i]==']') expr[i]='[';
        i++;
    }

    int n=chkparen(expr);
    string str;
    if(n==1)
    {
        intopo(expr);
        rev(expr);
        cout<<"Prefix is :"<<expr<<endl;
    }
    else
        cout<<n;
}