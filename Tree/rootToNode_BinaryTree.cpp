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

queue<int> rootToNode(Node* root,int val){
    
    queue<int> q;
    
    if(root==NULL)
    {
        return q;
    }
    
    if(root->val==val)
    {
        q.push(root->val);
        return q;
    }
    
    q=rootToNode(root->left,val);
    if(!q.empty())
    {
        q.push(root->val);
        return q;
    }
    else{
        q=rootToNode(root->right,val);
        if(!q.empty())
        {
            q.push(root->val);
        }
        return q;
    }
}

int main()
{
    cout<<"create tree"<<endl;
    Node* root=createTree(0,NULL);
    cout<<"Root to node print"<<endl;
    queue<int> q=rootToNode(root,4);
    while(!q.empty())
    {
        cout<<q.front();
        q.pop();
    }
    return 0;
}