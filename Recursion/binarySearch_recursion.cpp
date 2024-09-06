#include<iostream>
using namespace std;

bool isSorted(int arr[],int size)
{
    if(size==1 || size==0)
    return true;
    
    else if(arr[0]>arr[1])
    return false;
    
    else{
        return isSorted(arr+1,size-1);
    }
}

bool binarySearch(int arr[],int s,int e,int value)
{
    int mid=(s+e)/2;
    
    if(e-s==0)
    return false;
    
    
    
    else if(arr[mid]==value)
    return true;
    
    else{
        if(value<arr[mid])
            return binarySearch(arr,s,mid-1,value);
        
        else
            return binarySearch(arr,mid+1,e,value);
    }
    
    
}
int main(){
  cout<<"Enter an array";
  int arr[5];
  for(int i=0;i<5;i++)
  {
    cin>>arr[i];
  }
  int value;
  cout<<"What value do you want to search"<<endl;
  cin>>value;
  cout<<"Check whether it is sorted"<<endl;
  bool check=isSorted(arr,sizeof(arr)/sizeof(int));
  
  if(check==true)
  {
    bool ans=binarySearch(arr,0,sizeof(arr)/sizeof(int)-1,value);
    if(ans==true)
       cout<<"Yes it is present"<<endl;
    else
        cout<<"Not present"<<endl;
  }
  else{
      cout<<"No it is not sorted";
  }
  
}




