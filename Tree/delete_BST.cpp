#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* right;
    Node* left;
    Node(int val){
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


Node* nodeHelper(Node* root);
Node* leftEnd(Node* root);
Node* deleteBST(Node* root,int val)
{
 if(root==NULL)
 {
     return NULL;
 }

 else if(val<root->val)
    {
        root->left=deleteBST(root->left,val);
    }
 else if(val>root->val)
    {
        root->right=deleteBST(root->right,val);
    }
 else
    {
        root=nodeHelper(root);
    }
    return root;
}
 

Node* nodeHelper(Node* root)
{
    if(root->right==NULL)
    {
        return root->left;
    }
    else if(root->left==NULL)
    {
        return root->right;
    }
    else{
        Node* rootLeftEnd=leftEnd(root->left);
        rootLeftEnd->right=root->right;
        return root->left;
    }
    
}

Node* leftEnd(Node* root)
{
    if(root->right==NULL)
    {
        return root;
    }
    
    return leftEnd(root->right);
}

void preorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    Node* root=NULL;
    cout<<"DO you want to insert element"<<endl;
    int check;
    cin>>check;
    while(check!=0)
    {
        cout<<"Enter the value"<<endl;
        int val;
        cin>>val;
        root=insertBST(root,val);
        cout<<"DO you want to insert element"<<endl;
        cin>>check;
    }
    
    preorder(root);
    cout<<"Enter the element you want to delete"<<endl;
    int val;
    cin>>val;
    root=deleteBST(root,val);
    cout<<endl;
    preorder(root);
    return 0;
    
}
