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

void print(Node<int>* head)
{
    while(head != NULL)
    {
        cout << head -> data << " --> " ;
        head = head -> next;
    }
    cout << endl;
}


Node<int>* Swap(Node<int>* head, int first , int second){
    int i=0;
    Node<int>* temp1=head;
    if ((second-first)==1){
    while(i<first){
              head=head -> next;
              i++;
        }





}

