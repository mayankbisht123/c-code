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

Node* createBST(Node* root)
{
    int val;
    bool go;
    if(root==NULL)
    {
        cout<<"Enter the value of root"<<endl;
        cin>>val;
        root=new Node(val);
    }
    
    cout<<"Do you want to go to 'LEFT' of "<<root->val<<" then press 'true' otherwise 'false"<<endl;
    cin>>go;
    if(go)
    {
        cout<<"Enter the value left of "<<root->val<<endl;
        cin>>val;
        while(val>root->val)
        {
            cout<<"Enter the value smaller than "<<root->val<<endl;
            cin>>val;
        }
        Node* left=new Node(val);
        root->left=left;
        createBST(root->left);
    }
    else
    return root;
    
    
    
    cout<<"Do you want to go to 'RIGHT' "<<root->val<<" then press 'true' otherwise 'false"<<endl;
    cin>>go;
    if(go){
        cout<<"Enter the value right of "<<root->val<<endl;
        cin>>val;
        while(val<root->val)
        {
            cout<<"Enter the value larger than "<<root->val<<endl;
            cin>>val;
        }
        Node* right=new Node(val);
        root->right=right;
        createBST(root->right);
    }
    
    
    return root;
    
    
}

int main()
{
    Node* root=createBST(NULL);
    return 0;
}