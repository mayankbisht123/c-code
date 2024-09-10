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
    
    cout<<root->val;
    preorder(root->left);
    preorder(root->right);
}


int main()
{
    Node* root=NULL;
    root=insertBST(root,8);
    root=insertBST(root,6);
    root=insertBST(root,7);
    root=insertBST(root,9);
    root=insertBST(root,10);
    
    preorder(root);
    return 0;
}