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

void printLevelWise(TreeNode<int>* root)
{
    int depth=1;
    queue<TreeNode<int>*> q;
    q.enqueue(root);
    while(!q.isEmpty())
    {
        TreeNode<int>* frontnode= q.dequeue();
        frontnode -> data=depth;
        cout << frontnode -> data << ":";
        int count=0;
        for(int i=0; i< frontnode -> numChild(); i++)
        {
            frontnode -> getChild(i) -> data=depth+1;
            cout << frontnode -> getChild(i) -> data << ",";
            q.enqueue(frontnode -> getChild(i));
            count++;
            if (count==frontnode->numChild())  depth++;
        }

        cout << endl;
    }

}


int main()
{
    TreeNode<int>* root=takeInputLevelWise();
    cout<<endl;
    printLevelWise(root);
}
