#include<iostream>
using namespace std;
class node
{   
    public:
    int data;
    node *next;
    
        node()
        {
            
            next=NULL;
        }
        node(int ele, node *point=NULL)
        {
            data=ele;
            next=point;
        }


};

class CLinkedList 
{
    node *head=NULL;
    public:
        void addtohead(int);
        void addtoend(int);
        void insert(int,int);
        int del(int ele);
        bool search(int ele);
        void display();
        void reverse();

};

void CLinkedList:: addtohead(int ele)
{
    if(head==NULL)    
    {    head=new node(ele);
        head->next=head;
    }
    else
    {
        
        node *temp=head;
        while(temp->next!=head)
        {    temp=temp->next;
        }
        
        temp->next=new node(ele,head);
        head=temp->next;
        
    }
    
}
void CLinkedList:: addtoend(int ele)
{
    if(head==NULL)    
    {    head=new node(ele);
        head->next=head;
    }
    else
    {
        node *temp=head;
        while(temp->next!=head)
        {    temp=temp->next;
        }
        temp->next=new node(ele,head);
    }
}
void CLinkedList::insert(int ele, int ind)
{
    if(head==NULL)    
    {    head=new node(ele);
        head->next=head;
    }
    else
    {   
        node *temp=head;
        int i=1;
        while(temp->next!=head && i<(ind-1))
        {   
            temp=temp->next;
            i++;}

        node *succ;
        
        succ=temp->next;
        temp->next=new node(ele,succ);
    }
}
int CLinkedList::del(int ele)
{
    if(head==NULL)
    {
        cout<<"List is empty "<<endl;
        return 0;
    }
    else if(head->data==ele)
    {
        node *temp=head;
        while(temp->next!=head)
            temp=temp->next;
        temp->next=head->next;
        delete head;
        head=temp->next;
        return 1;
    }
    else
    {
        node *temp=head->next,*prev=head;
        int i=2;
        
        while(temp->next!=head)
        {
            if(temp->data==ele)
            {
                prev->next=temp->next;
                delete temp;
                return i;
            }
            prev=prev->next;
            temp=temp->next;
            i++;
        
        }
        if(temp->data==ele)
        {   
            prev->next=temp->next;
            delete temp;
            return i+1;
        }
        else 
            return 0;
            
        }
}

void CLinkedList:: display()
{
   
    if(head==NULL)
        cout<<"List is empty "<<endl;
    else
    {   
        cout<<"!<==============================================>!"<<endl;
        node *temp=head;
        while(temp->next!=head)
        {
            cout<<temp->data<<endl;
            temp=temp->next;
        }
        cout<<temp->data<<endl;
    }
}

bool CLinkedList::search(int ele)
{
    node *temp=head;
    int i=1;
    while(temp->next!=head)
    {
        if(temp->data==ele)
            return i;
        temp=temp->next;
        i++;
       
    }
    if(temp->data==ele)
        return i+1;
    else 
        return 0;

}
void CLinkedList::reverse()
{
    node *prev=head, *succ,*curr;
    curr=head;
    while(prev->next!=head)
        prev=prev->next;
    do
    {
        succ=curr->next;
        curr->next=prev;
        prev=curr;
        curr=succ;

    } while (curr!=head);
    head=prev;
}

int main()
{
 CLinkedList obj;
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
            int ele;
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