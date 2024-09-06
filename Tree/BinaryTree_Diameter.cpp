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
        cout<<"To stop going left "<<root->left->val<< " press -1 otherwise press any to "<<endl;
        cin>>k;
        createTree(k,root->left);
        
        cout<<"Enter the value to right of: "<<root->val<<endl;
        cin>>val;
        Node* newnode2=new Node(val);
        root->right=newnode2;
        cout<<"To stop going right "<<root->right->val<< " press -1 otherwise press any to "<<endl;
        cin>>k;
        createTree(k,root->right);
    }
    return root;
}

int Diameter(Node* root,int maxi,int key)
{
    if(root==NULL)
    {
        return 0;
    }
    
    int left=Diameter(root->left,maxi,key);
    int right=Diameter(root->right,maxi,key);
    
    maxi=left+right;
    
    if(key==root->val)
    {
        cout<<"Maximum path sum of node"<<root->val<<" is :"<<maxi<<endl;
    }
    
    return (max(left,right)+1);
}

int main()
{
    cout<<"create tree"<<endl;
    Node* root=createTree(0,NULL);
    Diameter(root,0,1);
    return 0;
}