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

vector<vector<int>> BFS_Zig_Zag(Node *root)
{
    vector<vector<int>> Bayle;
    if(root==NULL)
    {
        cout<<"No tree";
        return Bayle;
    }
    int size=0;
    bool leftTOright=true;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        size=q.size();
        vector<int> dummy(size);
        if(leftTOright==true)
        {
            for(int i=0;i<size;i++)
            {
                if(root->left!=NULL)
                {
                    q.push(root->left);
                }
                if(root->right!=NULL)
                {
                    q.push(root->right);
                }
                cout<<q.front()->val<<" ";
                dummy[i]=q.front()->val;
                q.pop();
                root=q.front();
            }
            cout<<endl;
            Bayle.push_back(dummy);
            leftTOright=false;
        }
        else
        {
            for(int i=size-1;i>=0;i--)
            {
                if(root->left!=NULL)
                {
                    q.push(root->left);
                }
                if(root->right!=NULL)
                {
                    q.push(root->right);
                }
                cout<<q.front()->val<<" ";
                dummy[i]=q.front()->val;
                q.pop();
                root=q.front();
            }
            cout<<endl;
            Bayle.push_back(dummy);
            leftTOright=true;
        }
    }
    return Bayle;
}
int main()
{
    cout<<"create tree"<<endl;
    Node* root=createTree(0,NULL);
    cout<<"Breath first search"<<endl;
    vector<vector<int>> Bayle=BFS_Zig_Zag(root);
    for(auto it:Bayle)
    {
        for(auto itt:it)
        {
            cout<<itt<<" ";
        }
        cout<<endl;
    }
    return 0;
}