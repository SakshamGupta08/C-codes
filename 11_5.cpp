#include <iostream>
#include "NodewithoutT.h"
using namespace std ;

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


int Mid(Node* head) {
if (head == NULL) {
    return -1 ;
}
Node* temp = head ;
Node* temp1 = head ;
while (temp1 -> next != NULL && temp1 -> next -> next != NULL) {
    temp = temp -> next ;
    temp1 = temp1 -> next -> next ;
}
return temp -> data ;
}


int main () {
Node* head = takeInputBetter() ;
//print(head) ;
int ans = Mid(head) ;
cout << "Mid is :" << ans << endl ;
}





