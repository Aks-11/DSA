#include<iostream>
using namespace std;
class node
{   
    public:
    int data;
    node *next ,*prev;
    
        node()
        {
            
            next=NULL;
            prev=NULL;
        }
        node(int ele, node *point=NULL, node *end=NULL)
        {
            data=ele;
            next=point;
            prev=end;
        }


};

class LinkedList 
{
    node *head=NULL;
    public:
    
        void addtohead(int);
        void addtoend(int);
        void insert(int ele, int ind);
        int del(int ele);
        bool search(int ele);
        void display();
        void reverse();
       
};

void LinkedList::addtohead(int ele)
{
    if(head==NULL)
    {
        head=new node(ele);
    }
    else 
    {
        head=new node(ele,head);

    }
}

void LinkedList::addtoend(int ele)
{
     if(head==NULL)
    {
        head=new node(ele);
    }
    
    else
    {
        node *temp=head;
        while(temp->next!=NULL)
        {temp=temp->next;}
    


        temp->next=new node(ele,NULL,temp);
    }

}

void LinkedList::insert(int ele, int ind)
{
    if(head==NULL)
    {
        head=new node(ele);
    }
    else if(ind==1)
    {
        head=new node(ele,head);

    }
    
    else 
    {
        
        node *temp=head;
        int i=1,flag=0;
        while(i<(ind-1))
        {   
            if(temp->next==NULL)
            {    flag=1;
                break;
            }
            temp=temp->next;
            i++;
        }
        if(flag==1)
            temp->next=new node(ele);
        else
        {
            node *succ;
            succ=temp->next;
            temp->next=new node(ele,succ,temp); 
            
        }


        
    }
    

}

int LinkedList::del(int ele)
{
    if(head==NULL)
    {    cout<<"List is empty"<<endl;
        return 0;
    }   
    else if(head->data==ele)
    {
        node *temp=head;
        head=head->next;
        temp->next=NULL;
        head->prev=NULL;
        delete temp;
        return 1;
    }
    else
    {
        node *beh=head, *temp=head->next;
        int i=2;
        while( temp!=NULL)
        {
            if(temp->data==ele)
                break;
            i++;
            temp=temp->next;
            beh=beh->next;
        }
        if(temp==NULL)
        {
            
            return 0;
        }
        else if(temp->next!=NULL)
        {
            node *succ=temp->next;
            beh->next=succ;
            succ->prev=beh;
            temp->next=NULL;
            temp->prev=NULL;

            delete temp;
            return i;
        }
        else
        {
            beh->next=NULL;
           
            temp->next=NULL;
            temp->prev=NULL;

            delete temp;
            return i;

        }
    }
}

void LinkedList::display()
{
    if(head==NULL)
        cout<<"List is empty"<<endl;
    else
    {
        cout<<"!<==============================================>!"<<endl;
        node *temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<endl;
            temp=temp->next;
        }
    }
}

bool LinkedList::search(int ele)
{
    
    node *temp=head;
   while( temp!=NULL)
    {
        if(temp->data==ele)
            break;
        temp=temp->next;
    }
    
    return temp!=NULL;
}

void LinkedList::reverse()
{
    node *curr, *succ, *prev=NULL;
    curr=head;
    
    
    while(curr!=NULL)
    {

        succ=curr->next;

         curr->next=prev;
        curr->prev=succ;
        prev=curr;
        curr=succ;
    }
    head=prev;
}

int main()
{
 LinkedList obj;
    int opt=0;
    while(opt!=8)
    {   

        cout<<"\n\nSelec 1 option"<<endl;
        cout<<"1)Insert to Head \n2)Insert to End \n3)Insert to index \n4)Delete \n5)Search \n6)Display \n7)Reverse \n8)Exit\n"<<endl;
    cin>>opt;
    switch(opt)
    {
        case 1:
        {
            int ele, ind;
            cout<<"Enter the element to insert in list "<<endl;
            cin>>ele;
            obj.addtohead(ele);
            break;
        }
        case 2:
        {
            int ele, ind;
            cout<<"Enter the element to insert in list "<<endl;
            cin>>ele;
            obj.addtoend(ele);
            break;
        }

        case 3:
        { 
            int ele, ind;
            cout<<"Enter the element to insert in list "<<endl;
            cin>>ele;
            cout<<"Enter the index of the element in list "<<endl;
            cin>>ind;
            obj.insert(ele,ind);
            break;
        }
            
        case 4:
        {
            int ele;
            cout<<"Enter the element to be deleted: "<<endl;
            cin>>ele;
            int flag=obj.del(ele);
            if(flag!=0)
                cout<<"Element is deleted at index "<<flag<<endl;
            else
                cout<<"Element is not present "<<endl;
            break;
        }
        case 5:
        {
            int ele;
            cout<<"Enter element to be found: "<<endl;
            cin>>ele;

            bool flag=obj.search(ele);
            if(flag)
                cout<<"Element is present in List "<<flag<<endl;
            else
                cout<<"Element is not present "<<endl;
            break;
        }
        case 6:
        {
            obj.display();
            break;
        }
        case 7:
        {
            obj.reverse();
            cout<<"Reversed List"<<endl;
            obj.display();
            break;
        }
       
        case 8:
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