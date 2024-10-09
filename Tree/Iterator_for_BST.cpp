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

class IteratorBST{
    private: 
    stack<Node*> s;
    void pushAll(Node* root)
    {
        if(root==NULL)
        {
            return;
        }
        s.push(root);
        pushAll(root->left);
        
    }
    public:
    IteratorBST(Node* root)
    {
        pushAll(root);
    }
    
    bool hasNext()
    {
        return !s.empty();
    }
    
    int next()
    {
        Node* temp=s.top();
        s.pop();
        if(temp->right!=NULL)
        {
            pushAll(temp->right);
        }
        return temp->val;
    }
};

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
    
    IteratorBST* obj=new IteratorBST(root);
    while(obj->hasNext())
    {
        int ch;
        cout << "Enter 1 for next number " << endl;
        cout << "Enter 2 for checking whether there is next number" << endl;
        cout << "Enter 3 for stopping" << endl;
        cin >> ch;
        switch(ch)
        {
            case 1:
            cout<<obj->next()<<endl;
            break;
            
            case 2:
            cout<<obj->hasNext()<<endl;
            break;
            
            case 3:
            exit(0);
            
            default:
            cout<<"You have entered wrong key"<<endl;
            break;
            
        }
    }
    return 0;
}