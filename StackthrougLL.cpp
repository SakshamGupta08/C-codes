#include <iostream>
#include "Stack2.h"
using namespace std;

int main()
{
    stack s;
    cout<<s.top()<<endl;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout<<"Size is:"<<s.length()<<endl;

    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<"Size is:"<<s.length()<<endl;
    cout<<s.top()<<endl;

    }



