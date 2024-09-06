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

vector<int> topBinaryTree(Node *root)
{
    vector<int> ans;
    if(root==NULL)
    {
        return ans;
    }
    int size=0;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    map<int,int> m;
    while(!q.empty())
    {
        size=q.size();
        for(int i=0;i<size;i++)
        {
            auto p=q.front();
            Node* node=p.first;
            int x=p.second;
            if(node->left!=NULL)
            {
                q.push({node->left,x-1});
            }
            if(node->right!=NULL)
            {
                q.push({node->right,x+1});
            }
            if(m.find(x)==m.end())
            {
                m[x]=node->val;
            }
            
            q.pop();
        }
    }
    for(auto it:m)
        {
            ans.push_back(it.second);
        }
        
    return ans;
    
}


int main()
{
    cout<<"create tree"<<endl;
    Node* root=createTree(0,NULL);
    vector<int> v=topBinaryTree(root);
    for(auto it:v)
    {
        cout<<it<<" ";
    }
    
    return 0;
}