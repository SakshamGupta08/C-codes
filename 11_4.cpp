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

Node* RemoveDup (Node* head) {
while (head -> data == head -> next -> data) {
head = head -> next ;
}
Node* temp = head ;
while (temp -> next!= NULL) {
    Node* temp1 = temp ;
    temp = temp -> next ;
    if (temp -> next != NULL) {
    while (temp -> data == temp -> next -> data) {
       temp = temp -> next ;
    }
temp1 -> next = temp ;
}
}
return head ;
}

int main () {
Node* head = takeInputBetter() ;
print(head) ;
Node* temp = RemoveDup(head) ;
print(temp) ;
}

