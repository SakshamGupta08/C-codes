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


Node* Swap (Node* head , int first , int second)
{
    Node* temp = head ;
    if (first == 0)
    {
        int i =0 ;
        while (i < second-1)
        {
            temp = temp -> next ;
            i++ ;
        }
        Node* temp1 = temp -> next ;
        temp -> next = head ;
        Node* temp2 = head -> next ;
        head -> next = temp1 -> next ;
        temp1 -> next = temp2 ;
        head = temp1 ;
    }
    else if (second == first+1)
    {
        Node* temp1=head -> next -> next ;
        int i=0 ;
        while(i < first-1)
        {
            temp1 = temp1 -> next ;
            temp = temp -> next ;
            i++ ;
        }
        Node* temp2 = temp1 -> next ;
        Node* temp3 = temp -> next ;
        temp -> next = temp1 ;
        temp1 -> next = temp3 ;
        temp3 -> next = temp2 ;
    }

    else
    {
        int i=0,j=0 ;
        Node* temp1=head ;
        while (i<first-1)
        {
            temp = temp -> next ;
            i++ ;
        }
        while (j<second-1)
        {
            temp1 = temp1 -> next ;
            j++ ;
        }
        Node* temp2 = temp -> next ;
        temp -> next = temp1 -> next ;
        Node* temp3 = temp1 -> next -> next ;
        temp1 -> next -> next = temp2 -> next;
        temp1 -> next = temp2 ;
        temp2 -> next = temp3 ;
    }
    return head ;
}

int main ()
{
    Node* head = takeInputBetter() ;
    print(head) ;
    Node* temp = Swap(head,3,4) ;
    print(temp) ;
}










