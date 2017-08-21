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


Node* kReverse(Node* head , int k) {
Node* temp = head ;
for (int i=0 ; i<k-1 ;i++) {
    temp = temp -> next ;
}
Node* head1 = temp -> next ;
Node *smallHead1 = Reverse_re(head1) ;
temp -> next = NULL ;
Node* smallHead = Reverse_re(head) ;
Node* temp1 = smallHead ;
while (temp1 -> next != NULL) {
    temp1 = temp1 -> next ;
}
temp1 -> next = smallHead1 ;
return smallHead ;
}

int main () {
Node* head = takeInputBetter();
print(head);
int n ;
cout << "Enter number : " ;
cin >> n ;
Node* temp = kReverse(head,n) ;
print(temp) ;
}
