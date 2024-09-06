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

bool isSymmetric(Node* root1,Node* root2)
{
    if(root1==NULL && root2==NULL)
    {
        return true;
    }
    if(root1->val!=root2->val)
    {
        return false;
    }
    
    return isSymmetric(root1->left,root2->right) && isSymmetric(root1->right,root2->left);
    
}

int main()
{
    cout<<"create tree"<<endl;
    Node* root=createTree(0,NULL);
    cout<<"Breath first search"<<endl;
    if(isSymmetric(root->left,root->right))
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"NO";
    }
    return 0;
}