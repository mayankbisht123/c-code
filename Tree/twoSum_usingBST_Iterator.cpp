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
    
    preorder(root->left);
    cout<<root->val<<" ";
    preorder(root->right);
}

class IteratorBST{
    private: 
    stack<Node*> s;
    bool isReverse;
    void pushAll(Node* root)
    {
        if(root==NULL)
        {
            return;
        }
        s.push(root);
        
        if(isReverse==false)
        {
        pushAll(root->left);
        }
        
        else
        {
            pushAll(root->right);
        }
        
    }
    
    
    public:
    IteratorBST(Node* root,bool isReverse)
    {
        this->isReverse=isReverse;
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
        
        if(isReverse==false)
        {
            if(temp->right!=NULL)
            {
                pushAll(temp->right);
            }
        }
        else{
            if(temp->left!=NULL)
            {
                pushAll(temp->left);
            }
        }
        return temp->val;
    }
};
class Solution{
    private:
    int a,b;
    IteratorBST* obj1;
    IteratorBST* obj2;
    
    public:
    Solution(Node* root)
    {
        obj1=new IteratorBST(root,false);
        obj2=new IteratorBST(root,true); 
        
        this->a=obj1->next();
        this->b=obj2->next();
    }
    
    bool twoSum(int key)
    {
        while(a<b)
        {
            cout<<a<<" "<<b<<endl;
            if(a+b==key)
            {
                return true;
            }
            if((a+b)>key)
            {
                b=obj2->next();
            }
            if((a+b)<key)
            {
                a=obj1->next();
            }
        }
        cout<<a<<" "<<b<<endl;
        return false;
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
    cout<<endl;
    
    Solution* obj=new Solution(root);
    cout<<"Enter the sum that you want to check"<<endl;
    int key;
    cin>>key;
    cout<<obj->twoSum(key);
    
    
    return 0;
}