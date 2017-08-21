#include <iostream>
#include "TreeNode.h"
#include "queue.h"
using namespace std;

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


bool find(TreeNode<int>* root,int x)
{
    if ((root -> data)==x) return true;
    bool ans;
    for(int i=0; i<root->numChild(); i++)
    {
        ans=find(root->getChild(i),x);
        if (ans==1) return true;
    }
    if (ans!=1) return false;
}

int nodes_greater(TreeNode<int>* root,int x)
{
    int count=0;
    for(int i=0; i< root -> numChild(); i++)
    {
        if ((root->getChild(i)->data)>x) count++;
        int number=nodes_greater(root->getChild(i),x);
        count=count+number;
    }
    return count;
}

int Sum(TreeNode<int>* root)
{
    int sum=root->data;
    for(int i=0; i< root -> numChild(); i++)
    {
        sum=sum+root->getChild(i)->data;
    }
}


TreeNode<int>* BestNode(TreeNode<int>* root)
{
    int max=Sum(root);
    TreeNode<int>* temp;
    for(int i=0; i< root -> numChild(); i++)
    {
        int sum2=Sum(root->getChild(i));
        temp=BestNode(root->getChild(i));
        if(sum2>max)
        {
            max=sum2;
            temp=root;
        }
    }
    return temp;
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

int Node_2ndLargest(TreeNode<int>* root)
{

    int max=Node_Largest(root);
    int max1=root -> data;
    for(int i=0; i< root -> numChild(); i++)
    {
        int largest=Node_Largest(root -> getChild(i));
        if (largest>=max1 && largest!=max)
        {
            max1 = largest;
        }
    }
    return max1;
}








int main()
{
    TreeNode<int>* root=takeInputLevelWise();
    cout<<endl;
    int k;
    cout<<"Enter number to find:"<<endl;
    cin>>k;
    cout << find(root,k)<<endl;
    cout<< "Enter number in consideration:" ;
    int x;
    cin>>x;
    cout<<endl;
    cout<<"No. of nodes greater than " << x << " is " << nodes_greater(root,x)<<endl;
    //cout<<"Best Node is : " << BestNode(root)->data;
    cout<<"No. of leaf nodes is: " << LeafNodes(root)<<endl;
    cout<<"Second largest node is : " << Node_2ndLargest(root)<<endl;

}
