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

class Correction{
  private:
  Node* prev,*first,*middle,*second;
  
  void inorder(Node* root)
  {
    if(root==NULL)
    {
        return;
    }
    
    inorder(root->left);
    
    if(prev!=NULL && (prev->val>root->val))
    {
        if(first==NULL)
        {
            first=prev;
            middle=root;
        }
        else{
            second=root;
        }
    }
    prev=root;
    cout<<root->val<<" ";
    inorder(root->right);
  }
  
  public:
   Correction()
   {
        prev=first=middle=second=NULL;
   }
  
  
  
  void correctBST(Node* root)
  {
    inorder(root);
    if(first && second)
    {
        first->val=first->val+second->val;
        second->val=first->val-second->val;
        first->val=first->val-second->val;
    }
    else{
        first->val=first->val+middle->val;
        middle->val=first->val-middle->val;
        first->val=first->val-middle->val;
    }
  }
};

int main()
{
    Node* root=new Node(5);
    root->left=new Node(2);
    root->left->left=new Node(1);
    root->left->right=new Node(4);
    root->right=new Node(6);
    root->right->left=new Node(3);
    
    Correction* obj=new Correction();
    obj->correctBST(root);
    cout<<endl;
    obj->correctBST(root);
}