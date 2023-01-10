#include<iostream>
using namespace std;
class node
{   
    public:
    int data;
    node *left,*right;
    
        node()
        {
            right=NULL;
            left=NULL;
        }
        node(int ele, node *next=NULL,node *back=NULL)
        {
            data=ele;
            right=next;
            left=back;
            
        }


};

class bst
{
    node *root=NULL;
    public:
    
        
        void insert(int ele);
     
        bool search(int ele);
        int inorder(node *temp);
        int preorder(node *temp);
        int postorder(node *temp);
        void disp();
   
};



void bst::insert(int ele)
{
    if(root==NULL)
    {
        root=new node(ele);
    }
   
    else 
    {
        
        node *temp=root;
      

        while(temp!=NULL)
        {
            if(ele>temp->data)
            {
                if(temp->right==NULL)
                {
                    temp->right=new node(ele);
                    break;
                }
                else    
                {temp=temp->right;}
            }
            else
            {   
                if(temp->left==NULL)
                {
                    temp->left=new node(ele);
                    break;
                }
                else
                {
                    temp=temp->left;
                }

            }
                
        }
        
    }
    

}


int bst::inorder(node *temp)
{
    if(temp==NULL)
        return 1;
    else
    {
        inorder(temp->left);
        cout<<temp->data<<" ";
        inorder(temp->right);
    }
}
int bst::preorder(node *temp)
{
    if(temp==NULL)
        return 1;
    else
    {
        cout<<temp->data<<" ";
        preorder(temp->left);
        preorder(temp->right);
    }
}
int bst::postorder(node *temp)
{
    if(temp==NULL)
        return 1;
    else
    {
        postorder(temp->left);
        postorder(temp->right);
        cout<<temp->data<<" ";
    }
}
void bst::disp()
{
    if(root==NULL)
        cout<<"BST is empty"<<endl;
    else
    {
        cout<<"\nInorder Traversal ";
        inorder(root);
        cout<<"\nPreorder Traversal ";
        preorder(root);
        cout<<"\nPostorder Traversal ";
        postorder(root);
    }
}

bool bst::search(int ele)
{
    
    node *temp=root;
   while( temp!=NULL)
    {
        if(temp->data==ele)
            break;
        else if(ele>temp->data)
            temp=temp->right;
        else
            temp=temp->left;
    }
    
    return temp!=NULL;
}


int main()
{
 bst obj;
    int opt=0;
    while(opt!=4)
    {   

        cout<<"\n\nSelec 1 option"<<endl;
        cout<<"1)Insert \n2)Search \n3)Display \n4)Exit\n"<<endl;
    cin>>opt;
    switch(opt)
    {
        case 1:
        {
            
            int ele, ind;
            cout<<"Enter the element to insert in BST "<<endl;
            cin>>ele;
          
            obj.insert(ele);
            break;
        }
            
       
        case 2:
        {
            int ele;
            cout<<"Enter element to be found: "<<endl;
            cin>>ele;

            bool flag=obj.search(ele);
            if(flag)
                cout<<"Element is present in BST "<<flag<<endl;
            else
                cout<<"Element is not present "<<endl;
            break;
        }
        case 3:
        {
            obj.disp();
            break;
        }
        
        case 4:
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