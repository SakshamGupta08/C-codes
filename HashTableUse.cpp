#include "HashTable.h"
#include <iostream>
using namespace std;
int main()
{
    HashTable<int>h;
    char a[]="abc";
    char b[]="def";
    char c[]="ghi";
    h.add(a,10);
    h.add(b,20);
    h.add(c,50);
    cout<<h.search(a)<<endl;
    h.deleteKey(a);
    cout<<h.search(a)<<endl;
    return 0;
}
