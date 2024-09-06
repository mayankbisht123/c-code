#include<iostream>
#include<bits/stdc++.h>
using namespace std;


bool sum(vector<int>& v,int k)
{
    int final=0;
    for(auto it:v)
    {
        final=final+it;
    }
    if(final==k)
    return true;
    
    return false;
    
}

void subSequence(int index,vector<int>& v,int m,int arr[],int k){
    if(index>=m)
    {
        if(sum(v,k))
        {
            for(auto it:v)
            {
                cout<<it<<" ";
            }
            cout<<endl;
        }
        return;
    }
    
    v.push_back(arr[index]);
    subSequence(index+1,v,m,arr,k);
    
    v.pop_back();
    subSequence(index+1,v,m,arr,k);
}

int main(){
    cout<<"Enter the size of array"<<endl;
    int m;
    cin>>m;
    int arr[m];
    vector<int> v;
    cout<<"Enter the array"<<endl;
    for(int i=0;i<m;i++)
    {
        cin>>arr[i];
    }
    
    cout<<"Enter the sum whoes sub sequence you have to find"<<endl;
    int k;
    cin>>k;
    cout<<endl;
    subSequence(0,v,m,arr,k);
}