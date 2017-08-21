#include <iostream>
#include "queue.h"
using namespace std;

int main(){
queue<int> q;
q.enqueue(1);
q.enqueue(2);
q.enqueue(3);
q.enqueue(4);
q.enqueue(5);
q.enqueue(6);
cout<<"Size is:"<<q.Size()<<endl;

while(!q.isEmpty()){
    cout<<q.dequeue()<<endl;
}
}

