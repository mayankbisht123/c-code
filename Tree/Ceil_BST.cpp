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

int cei(Node* root,int key)
{
    int ceili=-1;
    
    if(root==NULL)
    {
        return -1;
    }
    
    while(root!=NULL)
    {
        if(key==root->val)
        {
            return key;
        }
        
        if(key<root->val)
        {
            ceili=root->val;
            root=root->left;
        }
        if(key>root->val)
        {
            root=root->right;
        }
    }
    return ceili;
}

int main()
{
    Node* root=NULL;
    root=insertBST(root,8);
    root=insertBST(root,6);
    root=insertBST(root,7);
    root=insertBST(root,11);
    root=insertBST(root,9);
    root=insertBST(root,4);
    root=insertBST(root,2);
    
    preorder(root);
    cout<<endl;
    cout<<cei(root,3);
    return 0;
}