#include <iostream>
#include "Node.h"
using namespace std;

Node* takeInputBetter() {
    int data;
    cout << "Enter first element : ";
    cin >> data;
    Node* head = NULL;
    Node* tail = NULL;
    while(data != -1) {
        Node *newNode = new Node(data);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail -> next = newNode;
            tail = newNode;
        }
        cout << "Enter next element : ";
        cin >> data;
        }
    return head;
}

void print(Node *head) {
    while(head != NULL) {
        cout << head -> data << " --> " ;
        head = head -> next;
    }
    cout << endl;
}


int main() {
Node* head = takeInputBetter() ;
print(head) ;
Node* head1 = Even_odd(head) ;
print(head1) ;
 }



