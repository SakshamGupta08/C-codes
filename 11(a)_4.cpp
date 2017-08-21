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

Node* Del_alternate (Node* head, int k) {
//Node* realHead = head ;
if (k == 1) {
    head = head -> next ;
}
Node* prev = head ;
Node* temp = head -> next ;

while (prev != NULL && temp != NULL){
    prev -> next = temp -> next ;
    prev = prev -> next ;
    if (prev != NULL){
        temp = prev -> next ;
    }
}
return head ;
}


int main () {
Node* head = takeInputBetter() ;
print(head) ;
int n ;
cout << "Enter 0 or 1 : " ;
cin >> n ;
Node* head1 = Del_alternate(head,n) ;
print(head1) ;
}
