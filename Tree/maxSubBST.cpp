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

// class Correction{
//   private:
//   Node* prev,*first,*middle,*second;
  
//   void inorder(Node* root)
//   {
//     if(root==NULL)
//     {
//         return;
//     }
    
//     inorder(root->left);
    
//     if(prev!=NULL && (prev->val>root->val))
//     {
//         if(first==NULL)
//         {
//             first=prev;
//             middle=root;
//         }
//         else{
//             second=root;
//         }
//     }
//     prev=root;
//     cout<<root->val<<" ";
//     inorder(root->right);
//   }
  
//   public:
//   Correction()
//   {
//         prev=first=middle=second=NULL;
//   }
  
  
  
//   void correctBST(Node* root)
//   {
//     inorder(root);
//     if(first && second)
//     {
//         first->val=first->val+second->val;
//         second->val=first->val-second->val;
//         first->val=first->val-second->val;
//     }
//     else{
//         first->val=first->val+middle->val;
//         middle->val=first->val-middle->val;
//         first->val=first->val-middle->val;
//     }
//   }
// };

vector<int> maxSubBST(Node* root,vector<int> v)
{
    if(root==NULL)
    {
        return v;
    }
    vector<int> left=maxSubBST(root->left,v);
    vector<int> right=maxSubBST(root->right,v);
    
    if(left[1]<root->val && right[0]>root->val && (left[1]-1!=right[0] || (left[2]==0 && right[2]==0)) )
    {
        v[2]=left[2]+right[2]+1;
        v[0]=min(root->val,min(left[0],right[0]));
        v[1]=max(root->val,max(left[1],right[1]));
        cout<<left[1]<<" "<<root->val<<" "<<right[0]<<endl;
        for(auto it:v)
        {
            cout<<it<<" ";
        }
        cout<<endl;
        return v;   
    }
    
    cout<<left[1]<<" "<<root->val<<" "<<right[0]<<endl;
    v[2]=max(left[2],right[2]);
    return {INT_MIN,INT_MAX,v[2]};
    
}

int main()
{
    Node* root=new Node(5);
    root->left=new Node(2);
    root->left->left=new Node(1);
    root->left->right=new Node(4);
    root->right=new Node(6);
    root->right->left=new Node(3);
    root->right->left->left=new Node(19);
    
    // Correction* obj=new Correction();
    // obj->correctBST(root);
    // cout<<endl;
    // obj->correctBST(root);
    
    vector<int> ans=maxSubBST(root,{INT_MAX,INT_MIN,0});
    cout<<"The max subtree is: "<<ans[2];
    return 0;
}