#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void subSequence(int index,vector<int> v,int m,int arr[]){
    
    if(index>=m){
        for(auto it:v)
        {
            cout<<it;
        }
        cout<<endl;
        return;
    }
    
    
    v.push_back(arr[index]);
    subSequence(index+1,v,m,arr);
    v.pop_back();
    subSequence(index+1,v,m,arr);
}

int main()
{
    cout<<"Enter the size of array"<<endl;
    int m;
    cin>>m;
    cout<<"Enter your array"<<endl;
    int arr[m];
    vector<int> v;
    for(int i=0;i<m;i++)
    {
        cin>>arr[i];
    }
    
    cout<<"Print sub sequence";
    subSequence(0,v,m,arr);
}