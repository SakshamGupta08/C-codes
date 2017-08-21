#include <iostream>
#include "Node.h"
using namespace std ;

Node* takeInputBetter()
{
    int data;
    cout << "Enter first element : ";
    cin >> data;
    Node* head = NULL;
    Node* tail = NULL;
    while(data != -1)
    {
        Node *newNode = new Node(data);
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

void print(Node *head)
{
    while(head != NULL)
    {
        cout << head -> data << " --> " ;
        head = head -> next;
    }
    cout << endl;
}

Node* Merge (Node* head1 , Node* head2)
{
    Node* output = NULL ;
    if (head1 == NULL)
    {
        return head2 ;
    }
    if (head2 == NULL)
    {
        return head1 ;
    }
    if (head1 -> data < head2 -> data)
    {
        output = head1 ;
        output -> next = Merge(head1 -> next,head2) ;
    }
    else
    {
        output = head2 ;
        output -> next = Merge(head1, head2 -> next) ;
    }
    return output ;
}

Node* Reverse_re(Node* head)
{
    if (head == NULL || head -> next == NULL)
    {
        return head ;
    }
    Node* smallhead = Reverse_re(head -> next) ;
    Node* temp = smallhead ;
    while (temp -> next != NULL)
    {
        temp = temp -> next ;
    }
    temp -> next = head ;
    head -> next = NULL ;
    return smallhead ;
}


Node* Alternate_AscDesc (Node* head)
{
    Node* temp = head ;


    int main ()
    {
        Node* head = takeInputBetter() ;
        print(head) ;
        Node* temp = Alternate_AscDesc(head) ;
        print(temp) ;
    }


