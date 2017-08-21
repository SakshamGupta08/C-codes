#include <iostream>
#include "BinaryTreeNode.h"
#include "queue.h"
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

void printBetweenK1K2(BinaryTreeNode<int>* root,int K1,int K2)
{


    if(root==NULL) return;
    if (root->data>K2)
    {

        printBetweenK1K2(root->left,K1,K2);
    }



    else if (root->data<K1)
    {

        printBetweenK1K2(root->right,K1,K2);

    }

    else if (root->data>=K1 && root->data<=K2)
    {
        cout<<root->data<<" ";
        printBetweenK1K2(root->right,K1,K2);
        printBetweenK1K2(root->left,K1,K2);

    }
    cout<<endl;
}



int main()
{
    BinaryTreeNode<int>* root = takeInput();
    int k1,k2;
    cout<<"Enter k1 and k2: ";
    cin>>k1>>k2;
    printBetweenK1K2(root,k1,k2);
}


