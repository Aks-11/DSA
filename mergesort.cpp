#include<iostream>
using namespace std;

template<class T>
int merge(T arr[],int m,int mid,int n)
{
        int n1=mid-m+1;
        int n2=n-mid;
       
        T arr1[n1], arr2[n2];
        for(int j=0;j<n1;j++)
        {    arr1[j]=arr[m+j];
        }
        cout<<endl;
        for(int j=0;j<n2;j++)
        {    arr2[j]=arr[mid+j+1];}
       
        int i=0,j=0,k=m;
        while(i<n1 && j<n2)
        {
            if(arr1[i]<arr2[j])
            {
                arr[k]=arr1[i];
                i++;
            }
            else
            {
                arr[k]=arr2[j];
                j++;
            }
            k++;
        }
        while(i<n1)
        {
            arr[k]=arr1[i];
            i++;
            k++;
        }
        while(j<n2)
        {
            arr[k]=arr2[j];
            j++;
            k++;

        }
        
        
}
template<class T>
int mergesort(T arr[], int m, int n)
{
    if(m>=n)
        return 1;
    int mid= m + (n - m) / 2;

    
    mergesort(arr,m,mid);
    mergesort(arr,mid+1,n);
    merge(arr,m,mid,n);


}

int main()
{
    int n;
    cout<<"Enter number of elements "<<endl;
    cin>>n;
    int arr[n],ele;
    cout<<"\n Enter the elements "<<endl;
    for(int i=0;i<n;i++)
    {
            cin>>ele;
            arr[i]=ele;
    }
    mergesort(arr,0,n-1);
    cout<<"Sorted elements"<<endl;  
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
}