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

vector<vector<int>> vertical(Node *root)
{
    vector<vector<int>> ans;
    if(root==NULL)
    {
        cout<<"No tree";
        return ans;
    }
    int size=0;
    int x=0,y=0;
    queue<pair<Node*,pair<int,int>>> q;
    map<int,map<int,multiset<int>>> m;
    q.push({root,{0,0}});
    while(!q.empty())
    {
        size=q.size();
        for(int i=0;i<size;i++)
        {
            auto p=q.front();
            Node* node=p.first;
            x=p.second.first;
            y=p.second.second;
            if(node->left!=NULL)
            {
                q.push({node->left,{x-1,y+1}});
            }
            if(node->right!=NULL)
            {
                q.push({node->right,{x+1,y+1}});
            }
            m[x][y].insert(node->val);
            q.pop();
        }
    }
    
    for(auto it:m)
    {
        vector<int> dummy;
        for(auto itt:it.second)
        {
            dummy.insert(dummy.end(),itt.second.begin(),itt.second.end());
        }
        ans.push_back(dummy);
    }
    return ans;
    
}

int main()
{
    cout<<"create tree"<<endl;
    Node* root=createTree(0,NULL);
    vector<vector<int>> v=vertical(root);
    for(auto it:v)
    {
        for(auto itt:it)
        {
            cout<<itt<<" ";
        }
        cout<<endl;
    }
    return 0;
}