#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
  int val;
  Node* left;
  Node* right;
  
  Node(int val)
  {
      this->val=val;
      this->left=NULL;
      this->right=NULL;
  }
};


Node* createTree(int k,Node* root)
{
    int val;
    if(k==-1)
    {
        return NULL;
    }
    
    if(root==NULL)
    {
        cout<<"Enter the value of root node"<<endl;
        cin>>val;
        Node* newnode=new Node(val);
        root=newnode;
        createTree(k,root);
    }
    
    else{
        cout<<"Enter the value to left of: "<<root->val<<endl;
        cin>>val;
        Node* newnode=new Node(val);
        root->left=newnode;
        cout<<"To STOP going further of "<<root->left->val<< " press '-1' otherwise press '00' to "<<endl;
        cin>>k;
        createTree(k,root->left);
        
        cout<<"Enter the value to right of: "<<root->val<<endl;
        cin>>val;
        Node* newnode2=new Node(val);
        root->right=newnode2;
        cout<<"To STOP going further of "<<root->right->val<< " press '-1' otherwise press '00' to "<<endl;
        cin>>k;
        createTree(k,root->right);
    }
    return root;
}

vector<int> leftNode(Node* root,vector<int> v)
{
    if(root->right==NULL && root->left==NULL)
    {
        return v;
    }
    
    v.push_back(root->val);
    if(root->left!=NULL)
    {
        v=leftNode(root->left,v);
    }
    else{
        v=leftNode(root->right,v);
    }
    return v;
}

vector<int> leafNode(Node* root,vector<int> v)
{
    if(root->right==NULL && root->left==NULL)
    {
        v.push_back(root->val);
        return v;
    }
    
    if(root==NULL)
    {
        return v;
    }
    
    v=leafNode(root->left,v);
    v=leafNode(root->right,v);
    return v;
}

vector<int> rightNode(Node* root,vector<int> v)
{
    if(root->right==NULL && root->left==NULL)
    {
        return v;
    }
    if(root->right!=NULL)
    {
        v=rightNode(root->right,v);
    }
    else{
        v=rightNode(root->left,v);
    }
    v.push_back(root->val);
    return v;
}



int main()
{
    cout<<"create tree"<<endl;
    Node* root=createTree(0,NULL);
    vector<int> v;
    v=leftNode(root,v);
    v=leafNode(root,v);
    v=rightNode(root,v);
    for(auto it:v)
    {
        cout<<it<<" ";
    }
    
    return 0;
}
