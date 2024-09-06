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

Node* lowestAncestor(Node* root,int val1,int val2)
{
    if(root==NULL)
    {
        return NULL;
    }
    
    if(root->val==val1 || root->val==val2)
    {
        return root;
    }
    
    Node* left=lowestAncestor(root->left,val1,val2);
    Node* right=lowestAncestor(root->right,val1,val2);
    
    if(left==NULL)
    {
        return right;
    }
    else if(right==NULL)
    {
        return left;
    }
    else{
        return root;
    }
}

int main()
{
    cout<<"create tree"<<endl;
    Node* root=createTree(0,NULL);
    cout<<"LowestAncestor"<<endl;
    Node* ancestor=lowestAncestor(root,5,7);
    cout<<ancestor->val;
    return 0;
}