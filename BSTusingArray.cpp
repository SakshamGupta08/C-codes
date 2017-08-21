#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;

void print(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return;
    }
    cout << root -> data << " : ";
    if(root -> left != NULL)
    {
        cout << root -> left -> data ;
    }
    cout << ", ";
    if(root -> right != NULL)
    {
        cout << root -> right -> data;
    }
    cout << endl;
    print(root -> left);
    print(root -> right);

}

BinaryTreeNode<int>* BSTusingArray (int a[],int start,int last)
{
    if(start>last)return NULL;
    int mid=(start+last)/2;
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(a[mid]);
    root->left=BSTusingArray(a,start,mid-1);
    root->right=BSTusingArray(a,mid+1,last);
    return root;
}


int main()
{
    int a[50],n;
    cout<<"Size of array: ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    BinaryTreeNode<int>* root= BSTusingArray(a,0,n-1);
    print(root);
}
