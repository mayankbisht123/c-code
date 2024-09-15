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

void preorder(Node* root)
{
    if(root==NULL)
    return;
    
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

int floorBST(Node* root,int key,int flor)
{
    if(root==NULL)
    {
        return flor;
    }
    if(root->val==key)
    {
       return key;   
    }
    if(root->val<key && root->val>flor)
    {
        flor=root->val;
    }
    
    if(key<root->val)
    {
        return floorBST(root->left,key,flor);
    }
    if(key>root->val)
    {
        return floorBST(root->right,key,flor);
    }
}
    


int main()
{
    Node* root=NULL;
    // cout<<"DO you want to insert element"<<endl;
    // int check;
    // cin>>check;
    // while(check!=0)
    // {
    //     cout<<"Enter the value"<<endl;
    //     int val;
    //     cin>>val;
    //     root=insertBST(root,val);
    //     cout<<"DO you want to insert element"<<endl;
    //     cin>>check;
    // }
    
    
    root=insertBST(root,12);
    root=insertBST(root,8);
    root=insertBST(root,15);
    root=insertBST(root,6);
    root=insertBST(root,10);
    root=insertBST(root,3);
    root=insertBST(root,7);
    root=insertBST(root,9);
    root=insertBST(root,11);
    root=insertBST(root,14);
    root=insertBST(root,16);
    
    preorder(root);
    
    
    cout<<endl<<"Enter the key"<<endl;
    int key;
    cin>>key;
    int flor=floorBST(root,key,0);
    if(flor==0)
    {
        cout<<"Not found"<<endl;
    }
    else{
        cout<<flor;
    }
    return 0;
}