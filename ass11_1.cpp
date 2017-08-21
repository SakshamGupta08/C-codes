#include <iostream>
#include "Node.h"
using namespace std;

Node<int>* takeInputBetter()
{
    int data;
    cout << "Enter first element : ";
    cin >> data;
    Node<int>* head = NULL;
    Node<int>* tail = NULL;
    while(data != -1)
    {
        Node<int>* newNode = new Node<int>(data);
        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail -> next = newNode;
            tail = newNode;
        }
        cout << "Enter next element : ";
        cin >> data;
    }
    return head;
}


Node<int>* Insert(Node<int>* head,int pos,int data)
{
    Node<int>* newnode= new Node<int>(data);
    if(pos==0)
    {
        newnode->next=head;
        return newnode;
    }
    head->next=Insert(head->next,pos-1,data);
    return head;

}

Node<int>* Delete(Node<int>* head,int pos)
{
    if(pos==0)
    {
        head=head -> next;
        return head;
    }
    head -> next =Delete(head->next,pos-1);
    return head;

}


void print(Node<int>* head)
{
    while(head != NULL)
    {
        cout << head -> data << " --> " ;
        head = head -> next;
    }
    cout << endl;

}

int main()
{
    Node<int>* head=takeInputBetter();
    print(head);
    int a,b;
    cout<<"Enter data and position to insert it in:";
    cin>>b>>a;
    Node<int>* temp=Insert(head,a,b);
    print(temp);
    int c;
    cout<<"Enter position to delete:";
    cin>>c;
    Node<int>* temp1=Delete(head,c);
    print(temp1);

}
