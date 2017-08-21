#include <iostream>
using namespace std;
template<typename T>
//Templates to be used as stack<int> s or stack<char> s.
class stack
{
public:
    T *data;
    int nextindex;
    int capacity;

    stack()
    {
        capacity=5;
        data=new T[capacity];
    }
    /*stack(int n)
    {
        data=new int[n];
        nextindex=0;
        capacity=n;
    }
    */
    int size()
    {
        return nextindex;
    }
    bool isEmpty()
    {
        return nextindex==0;
    }

    T top()
    {
        if(nextindex==0)
        {
            cout<<"Stack is Empty!";
            return -1;
        }
        T ans=data[nextindex-1];
        return ans;
    }

    void push(T element)
    {
        if(nextindex==capacity)
        {
            //DYNAMIC ARRAY
            T *temp=data;
            data=new T[2*capacity];
            for(int i=0; i<capacity; i++)
            {
                data[i]=temp[i];
            }
            capacity=2*capacity;

            //cout<<"Stack overflow!";
            //return;
            delete [] temp;
        }
        data[nextindex]=element;
        nextindex++;
    }
    T pop()
    {
        if(nextindex==0)
        {
            cout<<"Stack is empty!";
            return -1;
        }
        T ans=data[nextindex-1];
        nextindex--;
        return ans;
    }

};
