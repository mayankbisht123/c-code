#include<iostream>
using namespace std;

int sum(int arr[],int size)
{
    if(size==0)
    return 0;
    
    int add=arr[0]+sum(arr+1,size-1);
    return add;
}

int main()
{
    cout<<"Enter the size of array"<<endl;
    int m;
    cin>>m;
    cout<<"Enter your array"<<endl;
    int arr[m];
    for(int i=0;i<m;i++)
    {
        cin>>arr[i];
    }
    
    int add=sum(arr,m);
    cout<<"The sum of elements of array is :"<<add;
}


