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

void preorder(Node* root)
{
    if(root==NULL)
    return;
    
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

int LCAbst(Node* root,int val1,int val2)
{
    if(root==NULL)
    {
        return -1;
    }
    else if(val1<root->val && val2<root->val)
    {
        return LCAbst(root->left,val1,val2);
    }
    else if(val1>root->val && val2>root->val)
    {
        return LCAbst(root->right,val1,val2);
    }
    else{
        return root->val;
    }
    
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
    
    preorder(root);
    
    cout<<"Enter the two numbers whoes LCA you want to find out"<<endl;
    int val1,val2;
    cin>>val1>>val2;
    cout<<"The LCA of "<<val1<<" and "<<val2<<" is "<<LCAbst(root,val1,val2);
    return 0;
}