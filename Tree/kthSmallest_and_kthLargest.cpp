#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
int val;
Node* right;
Node* left;

Node(int val)
{
    this->val=val;
    this->right=NULL;
    this->left=NULL;
}
};

Node* insertBST(Node* root,int val)
{
    if(root==NULL)
    {
        root=new Node(val);
    }
    
    else if(val<root->val)
    {
        root->left=insertBST(root->left,val);
    }
    else{
        root->right=insertBST(root->right,val);
    }
    return root;
}

void inorder(Node* root)
{
    if(root==NULL)
    return;
    
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

int kthSmallest(Node* root,int k,int& count)
{
    if(root==NULL)
    {
        return 0;
    }

    int left=kthSmallest(root->left,k,count);
    if(left!=0)
    {
    return left;
    }
    
    
    count++;
    if(count==k)
    {
        return root->val;
    }
    
    
    int right=kthSmallest(root->right,k,count);
    if(right!=0)
    {
        return right;
    }
    
    return 0;
}

int kthLargest(Node* root,int k,int& count)
{
    if(root==NULL)
    {
        return 0;
    }
    
    
    int right=kthLargest(root->right,k,count);
    if(right!=0)
    {
        return right;
    }
    
    count++;
    if(count==k)
    {
        return root->val;
    }
    
    
    int left=kthLargest(root->left,k,count);
    if(left!=0)
    {
        return left;
    }
    
    return 0;
}

int main()
{
    Node* root=NULL;
    // cout<<"DO you want to insert element"<<endl;
    // int check;
    // cin>>check;
    // while(check!=0)
    // {
    //     cout<<"Enter the value"<<endl;
    //     int val;
    //     cin>>val;
    //     root=insertBST(root,val);
    //     cout<<"DO you want to insert element"<<endl;
    //     cin>>check;
    // }
    
    root=insertBST(root,12);
    root=insertBST(root,8);
    root=insertBST(root,15);
    root=insertBST(root,6);
    root=insertBST(root,10);
    root=insertBST(root,3);
    root=insertBST(root,7);
    root=insertBST(root,9);
    root=insertBST(root,11);
    root=insertBST(root,14);
    root=insertBST(root,16);
    
    
    inorder(root);
    
    cout<<endl<<"Enter the kth value"<<endl;
    int k;
    cin>>k;
    int c=0;
    cout<<endl<<"The kth smallest is "<<kthSmallest(root,k,c)<<endl;
    c=0;
    cout<<"The kth largest is "<<kthLargest(root,k,c)<<endl;
    
    return 0;
}