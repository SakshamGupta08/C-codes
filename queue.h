#include "Node.h"
template <typename T>
class queue
{
public:
    Node<T>* head;
    Node<T>* tail;
    int size;

    queue()
    {
        head=NULL;
        tail=NULL;
        size=0;
    }

    int Size()
    {
        return size;
    }

    bool isEmpty()
    {
        return size==0;
    }

    T front()
    {
        if(size==0)
        {
            return 0;
        }
        return head->data;
    }

    void enqueue(T element)
    {
        Node<T>* newnode=new Node<T>(element);
        if(head==NULL)
        {
            head=newnode;
            tail=newnode;
        }
        else
        {
            tail->next=newnode;
            tail=newnode;
        }
        size++;
    }

    T dequeue()
    {
        Node<T>* temp=head;
        head=head->next;
        size--;
        return temp->data;
        delete temp;
    }
};
