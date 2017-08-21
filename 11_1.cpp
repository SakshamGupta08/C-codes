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

Node* DeleteRe(Node* head, int i)
{
    Node* temp = head ;
    if (i==0)
    {
        return head -> next ;
    }
    head -> next = DeleteRe(head -> next,i-1) ;
    return head ;
}

int main ()
{
    Node* head = takeInputBetter() ;
    print(head) ;
    Node* temp = DeleteRe(head,5) ;
    print(temp) ;

}

