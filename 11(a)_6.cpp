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

int FindLengthRe(Node *head) {
if (head == NULL) {
    return 0 ;
}
else {
    return FindLengthRe(head->next)+1 ;
}
}

void print(Node *head) {
    while(head != NULL) {
        cout << head -> data << " --> " ;
        head = head -> next;
    }
    cout << endl;
}

Node* Append(Node* head, int n) {
int len = FindLengthRe(head) ;
int i = 0;
Node* realHead = head ;
Node* temp = head ;
for (i=0 ; i<(len-n-1) ;i++) {
    temp = temp -> next ;
}
head = temp -> next ; ;
Node* temp1 = head ;
while (temp1 -> next != NULL){
    temp1 = temp1 -> next ;
}
temp1 -> next = realHead ;
temp -> next = NULL ;
return head ;
}

int main () {
Node* head = takeInputBetter() ;
print(head) ;
int k ;
cout << "Enter number : " ;
cin >> k ;
Node* head1 = Append(head,k) ;
print(head1) ;
 }
