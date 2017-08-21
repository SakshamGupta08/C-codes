#include <cstring>
template <typename V>
class HashNode{
public:
    char *key;
    V value;
    HashNode<V> *next;
    HashNode(char *key,V value){
        //this->key=hey; //shallow copy,if any changes in main then changes will be observed here also that we dont want
        this->key=new char[strlen(key)+1];
        strcpy(this->key,key);
        this->value=value;
        next=NULL;
    }
    ~HashNode()
    {
        delete [] key;///deleting he string
        if(next){///this means if(next!=NULL)
            delete next;///destructor is calling itself
        }
    }
};
