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

int getheight(BinaryTreeNode<int>* root)
{
    if (root==NULL) return 0;
    int h1=getheight(root -> left);
    int h2=getheight(root -> right);
    if (h1>=h2) return (h1 +1);
    else return (h2+1);

}


BinaryTreeNode<int>* find(BinaryTreeNode<int>* root,int value)
{
    if (root==NULL) return NULL;
    if((root->data)==value) return root;
    BinaryTreeNode<int>* child1= find(root -> left,value);
    if(child1==NULL)
    {
        BinaryTreeNode<int>* child2= find(root -> right,value);
        return child2;
    }
}


void mirror(BinaryTreeNode<int>* root)
{
    if (root==NULL) return;
    BinaryTreeNode<int>* temp= root-> left;
    root -> left = root-> right;
    root -> right= temp;
    mirror(root->left);
    mirror(root->right);
}

/*int diameter(BinaryTreeNode<int>* root)
{
    if(root==NULL) return 0;
    int option1= getheight(root->left) + getheight(root->right) + 1;
    int option2=diameter(root->left);
    int option3=diameter(root->right);
    return max(option1,max(option2,option3));

}
*/

class DoubleAns
{
public:
    int height;
    int diameter;
};

DoubleAns diameter_better(BinaryTreeNode<int>* root)
{
    if (root==NULL)
    {
        DoubleAns ans;
        ans.diameter=0;
        ans.height=0;
        return ans;

    }
    DoubleAns left=diameter_better(root -> left);
    DoubleAns right=diameter_better(root -> right);
    DoubleAns output;
    int h=max(left.height,right.height)+1;
    int option3=left.height + right.height +1;
    int d=max(left.diameter,max(right.diameter,option3));
    output.height=h;
    output.diameter=d;
    return output;
}
















//1 2 3 4 5 -1 -1 6 -1 -1 -1 -1 -1

int main()
{
    BinaryTreeNode<int>* root = takeInput();
    print(root);
    cout << "Height is:" << getheight(root) << endl;
    int k;
    cout<<"Enter number to find:";
    cin>>k;
    cout<<find(root,k)<<" "<<find(root,k)-> data << endl;
    mirror(root);
    print(root);
    cout << "diameter of tree is: " << diameter_better(root).diameter;
}
