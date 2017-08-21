#include <iostream>
#include "BinaryTreeNode.h"
#include "queue.h"
#include <climits>
using namespace std;

BinaryTreeNode<int>* takeInput()
{
    int rootData;
    cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.enqueue(root);
    while(!q.isEmpty())
    {
        BinaryTreeNode<int>* currentNode = q.dequeue();
        int leftChild;
        cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1)
        {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode ->left = leftNode;
            q.enqueue(leftNode);
        }
        int rightChild;
        cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1)
        {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode ->right = rightNode;
            q.enqueue(rightNode);
        }

    }
    return root;
}

int findMin(BinaryTreeNode<int>* root)
{
    if(root==NULL) return INT_MAX;
    return min(findMin(root->left),min(findMin(root->right),root->data));
}

int findMax(BinaryTreeNode<int>* root)
{
    if(root==NULL) return INT_MIN;
    return max(findMax(root->left),max(findMax(root->right),root->data));
}
//Try doing this by making a Class which contains min,max and isBST. We won't have to find max and min every time now.
bool CheckBST_1(BinaryTreeNode<int>* root)
{
    if(root==NULL) return true;
    int leftMax=findMax(root->left);
    int rightMin=findMin(root->right);
    if(root->data>=leftMax && root->data < rightMin)
    {
        bool leftans=CheckBST_1(root->left);
        bool rightans=CheckBST_1(root->right);
        return leftans && rightans;
    }
    else return false;

}



bool CheckBST(BinaryTreeNode<int>* root)
{
    if(root==NULL) return true;
    if(root->left==NULL && root->right==NULL) return true;
    else if(root->left==NULL)
    {
        if(root->right->data > root->data) return CheckBST(root->right);
    }
    else if(root->right==NULL)
    {
        if(root->left->data<=root->data) return CheckBST(root->left);
    }

    else
    {
        if(root->left->data<=root->data && root->right->data>root->data)
        {
            bool leftans=CheckBST(root->left);
            bool rightans=CheckBST(root->right);
            return leftans && rightans;
        }
    }
    return false;
}


Node<int>* Convert_LL(BinaryTreeNode<int>* root){

if(root==NULL) return NULL;
Node<int>* head1=Convert_LL(root->left);
Node<int>* head2=Convert_LL(root->right);
Node<int>* Root= new Node<int>(root->data);
Node<int>* temp=head1;
if(head1!=NULL){
while (temp->next!=NULL) temp=temp->next;
temp->next=Root;
Root->next=head2;
return head1;
}
else {
    Root->next=head2;
    return Root;
}
}

void print(Node<int>* head){
    while(head!=NULL){
        cout<<head->data<<"--->";
        head=head->next;
    }
    cout<<endl;

}



int main()
{
    BinaryTreeNode<int>* root = takeInput();
    //cout<<CheckBST(root)<<endl;
    Node<int>* head=Convert_LL(root);
    print(head);
}
