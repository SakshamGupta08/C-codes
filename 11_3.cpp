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

int isPalin(Node* head) {
Node* mid = head ;
Node* temp = head ;
Node* temp1 = head -> next ;
int count = 1 ;
while (temp1 != NULL || temp1 -> next != NULL) {
    mid = mid -> next ;
    temp1 = temp1 -> next -> next ;
    count++ ;
}
while (count>1) {
Node* temp2 = mid ;
int i=0,j=0 ;
while (i<count-2){
    temp = temp -> next ;
    i++ ;
    }
for (j=0 ; j<count-i-1; j++){
    temp2 = temp2 -> next ;
}
if (temp -> data == temp2 -> data) {
    count -- ;
}
else return -1 ;
}
return 1 ;
}


int main () {
    Node* head = takeInputBetter() ;
    print(head) ;
    cout << "Check Palindrome :" << isPalin(head) << endl ;
}
