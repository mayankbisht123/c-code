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

Node* tree(vector<int> pre,int preStart,int preEnd,vector<int> in,int inStart,int inEnd,map<int,int> inMap)
{
    if(preStart>preEnd || inStart>inEnd)
    {
        return NULL;
    }
    
    Node* root=new Node(pre[preStart]);
    int inRoot=inMap[root->val];
    int nextLeft=inRoot-inStart;
    
    root->left=tree(pre,preStart+1,preEnd+nextLeft,in,inStart,inRoot-1,inMap);
    root->right=tree(pre,preStart+nextLeft+1,preEnd,in,inRoot+1,inEnd,inMap);
    
    return root;
}

void preorderTraversal(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    
    cout<<root->val<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
    
}


int main()
{
    vector<int> preorder={10,20,40,50,30,60};
    vector<int> inorder={40,20,50,10,60,30};
    map<int,int> inMap;
    int i=0;
    for(auto it:inorder)
    {
        inMap[it]=i++;
    }
    
    Node* root=tree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inMap);
    preorderTraversal(root);
    return 0;
}