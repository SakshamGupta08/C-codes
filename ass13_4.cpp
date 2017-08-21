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




bool Identical(TreeNode<int>* a,TreeNode<int>* b)
{
    if (CountNodes(a)!=CountNodes(b)) return false;
    if(height(a)!=height(b)) return false;
    if (a->data==b->data)
    {
        for(int i=0; i<a->numChild(); i++)
        {
            bool ans=Identical(a->getChild(i),b->getChild(i));
            if (ans==0) return false;
        }
        return true;
    }
}


int main()
{
    TreeNode<int>* root1=takeInputLevelWise();
    cout<<endl;
    TreeNode<int>* root2=takeInputLevelWise();
    cout<<endl;
    cout<<Identical(root1,root2)<<endl;
}
