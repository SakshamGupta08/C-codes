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

Node* Reverse (Node* head) {
Node* prev = NULL ;
while (head != NULL) {
Node* next = head -> next ;
head -> next = prev ;
prev = head ;
head = next ;
}
return prev ;
}

Node* Reverse_re(Node* head){
if (head == NULL || head -> next == NULL) {
    return head ;
}
Node* smallhead = Reverse_re(head -> next) ;
Node* temp = smallhead ;
while (temp -> next != NULL) {
    temp = temp -> next ;
}
temp -> next = head ;
head -> next = NULL ;
return smallhead ;
}

int main() {
Node* head = takeInputBetter() ;
print(head) ;
Node* temp = Reverse_re(head) ;
print(temp) ;
Node* temp1 = Reverse(temp) ;
print(temp1) ;
}
