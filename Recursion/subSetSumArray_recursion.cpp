#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> subsetSum(int m,int arr[],int index,vector<int> v,int sum){
    if(index==m)
    {
        v.insert(v.begin(),sum);
        return v;
    }
    
    sum=sum+arr[index];
    v=subsetSum(m,arr,index+1,v,sum);
    
    sum=sum-arr[index];
    v=subsetSum(m,arr,index+1,v,sum);
    
    return v;

}

int main()
{
    cout<<"Enter the size of array"<<endl;
    int m;
    cin>>m;
    int arr[m];
    cout<<"Enter the array"<<endl;
    for(int i=0;i<m;i++)
    {
        cin>>arr[i];
    }
    cout<<"The array of sum is :"<<endl;
    vector<int> v,sumArr;
    vector<int> ans=subsetSum(m,arr,0,v,0);
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
}