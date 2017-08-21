#include "Node.h"
class stack
{
public:
    Node* head;
    int size;
    stack()
    {
        head=NULL;
        size=0;
    }
    int length()
    {
        return size;
    }
    bool isEmpty()
    {
        return size==0;
    }

    int top()
    {
        if(size==0) return -1;
        return head -> data;
    }
    void push(int element)
    {
        Node* newnode= new Node(element);
        newnode -> next = head;
        head=newnode;
        size++;
    }
    int pop()
    {
        if (size==0) return -1;
        int ans= head -> data;
        Node* temp=head;
        head= head -> next;
        delete temp;
        size--;

        return ans;
    }

};

