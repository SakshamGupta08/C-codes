#include <iostream>
#include "TreeNode.h"
#include "queue.h"
using namespace std;

/* TreeNode<int>* takeInput()
{
    cout<<"Enter root data:";
    int data;
    cin>>data;
    TreeNode<int>* root=new TreeNode<int>(data);
    cout<<"Enter no. of children of " << data << ":";
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        TreeNode<int>* childRoot = takeInput();
        root -> addChild(childRoot);
    }

    return root;
} */

TreeNode<int>* takeInputLevelWise()
{
    int rootdata;
    cout<<"Enter root: ";
    cin >> rootdata;
    TreeNode<int>* root= new TreeNode<int>(rootdata);
    queue<TreeNode<int>*> q;
    q.enqueue(root);
    while(!q.isEmpty())
    {
        TreeNode<int>* frontnode= q.dequeue();
        cout<< "Enter no. of child of " << frontnode -> data << ":";
        int n;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cout<<"Enter "<<i<<"th child of "<<frontnode -> data << ":";
            int childData;
            cin>>childData;
            TreeNode<int>* child= new TreeNode<int>(childData);
            q.enqueue(child);
            frontnode -> addChild(child);

        }
    }
    return root;
}

void print(TreeNode<int>* root)
{
    cout << root -> data << ":";
    for(int i=0; i< root -> numChild(); i++)
    {
        cout << root -> getChild(i) -> data << ",";
    }
    cout<<endl;
    for(int i=0; i< root -> numChild(); i++)
    {
        print(root -> getChild(i));
    }
}

void printLevelWise(TreeNode<int>* root)
{

    queue<TreeNode<int>*> q;
    q.enqueue(root);
    while(!q.isEmpty())
    {
        TreeNode<int>* frontnode= q.dequeue();
        cout << frontnode -> data << ":";
        for(int i=0; i< frontnode -> numChild(); i++)
        {
            cout << frontnode -> getChild(i) -> data << ",";
            q.enqueue(frontnode -> getChild(i));
        }
        cout << endl;
    }

}

int height(TreeNode<int>* root)
{
    int h=0;
    for(int i=0; i< root -> numChild(); i++)
    {
        int childheight=height(root -> getChild(i));
        if(childheight>h)
        {
            h=childheight;
        }
    }
    return h+1;
}

int CountNodes(TreeNode<int>* root)
{
    int count=0;
    for(int i=0; i< root -> numChild(); i++)
    {
        int nodes=CountNodes(root -> getChild(i));
        count=count+nodes;
    }
    return count+1;
}


int Sum_Nodes(TreeNode<int>* root)
{
    int sum=0;
    for(int i=0; i< root -> numChild(); i++)
    {

        int sumchild=Sum_Nodes(root -> getChild(i));
        sum=sum + sumchild;
    }
    return sum+(root -> data);
}

int Node_Largest(TreeNode<int>* root)
{
    int max=root -> data;
    for(int i=0; i< root -> numChild(); i++)
    {
        int largest=Node_Largest(root -> getChild(i));
        if (largest>=max)
        {
            max = largest;
        }
    }
    return max;
}

int LeafNodes(TreeNode<int>* root)
{
    int count=0;
    for(int i=0; i< root -> numChild(); i++)
    {
        if ((root->getChild(i)-> numChild())==0) count++;
        int number=LeafNodes(root->getChild(i));
        count=count+number;
    }
    return count;
}

/*void printdepth(TreeNode<int>* root,int depth)
{   int level=depth;
for (int i=0;i< root-> numChild();i++){
    if (level==0) {


            cout<< root->data << ",";
        }
    else {
            root=root->getChild(i);
        printdepth(root,level-1);
    }
}

    }*/
void printdepth(TreeNode<int>* root,int depth) {
if (root == NULL || depth < 0)  return;

    if (depth==1)
    {
        cout << root->data << endl;
        return;
    }
    for(int i=0; i< root-> numChild();i++){

    printdepth(root-> getChild(i), depth-1);
}
}

void preOrder(TreeNode<int>* root){
cout<<root -> data<< ","}




//1 3 2 3 4 0 0 2 5 6 0 1 7 0

int main()
{
    TreeNode<int>* root=takeInputLevelWise();
    cout<<endl;
    printLevelWise(root);
    cout << "Height of tree is : "<< height(root)<<endl;
    cout<< "No. of nodes in the tree is: "<< CountNodes(root)<<endl;
    cout<< "Sum of nodes in the tree is: "<< Sum_Nodes(root)<<endl;
    cout<< "Node with max value is: "<<Node_Largest(root)<<endl;
    cout<<"No. of leaf nodes is : " <<LeafNodes(root)<<endl;
    cout << "Enter depth : ";
    int k;
    cin>>k;
    printdepth(root,k);

}

