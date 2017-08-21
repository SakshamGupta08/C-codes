#include "HashNode.h"
#include <iostream>
#include <cstring>
using namespace std;
template <typename V>
class HashTable{
public:
    HashNode<V>**buckets;
    int tableSize;
    int numElements;///represents total number of  elements in the bucket

    HashTable(){
        tableSize=5;
        buckets=new HashNode<V>*[tableSize];
        for(int i=0;i<tableSize;i++)
        {
            buckets[i]=NULL;
        }
        numElements=0;
    }
    int getIndex(char *key){
        int currentIndex=strlen(key)-1;
        int index=0;
        int currentPower=1;
        while(currentIndex>=0){
            index+=key[currentIndex]*currentPower;
            currentPower*=37;
            currentIndex--;
        }
        return index%tableSize;
    }
    void rehash(){
        numElements=0;
        int prevSize=tableSize;
        tableSize=tableSize*2;
        HashNode<V>**temp=buckets;
        buckets=new HashNode<V>*[tableSize];
        for(int i=0;i<tableSize;i++)
        {
            buckets[i]=NULL;
        }
        for(int i=0;i<prevSize;i++)
        {
            HashNode<V>*head=temp[i];
            while(head!=NULL){
                add(head->key,head->value);
                head=head->next;
            }
        }
        delete [] temp;
    }
    void add(char *key,V value){
        int index=getIndex(key);
        HashNode<V>*head=buckets[index];
        HashNode<V>*newNode=new HashNode<V>(key,value);
        ///check if already present
        HashNode<V>*temp=head;
        while(temp!=NULL)
        {
            if(strcmp(temp->key,key)==0)
            {
                temp->value=value;
                return;
            }
            temp=temp->next;
        }
        newNode->next=head;
        head=newNode;
        buckets[index]=head;
        numElements++;
        double loadFactor=(numElements*1.0)/tableSize;
        if(loadFactor>=0.7){
            rehash();
        }
    }
    V search(char *key){
        int index=getIndex(key);
        HashNode<V>*head=buckets[index];
        while(head!=NULL)
        {
            if(strcmp(head->key,key)==0)
                return head->value;
            head=head->next;
        }
        cout<<"Key Not Found!"<<endl;
        return 0;
    }
    void deleteKey(char *key){
        int index=getIndex(key);
        HashNode<V>*head=buckets[index];
        HashNode<V>*prev=NULL;
        while(head!=NULL)
        {
            if(strcmp(head->key,key)==0){
                if(prev!=NULL){
                    prev->next=head->next;
                    delete head;
                    numElements--;
                    return;
                }
                buckets[index]=head->next;
                head->next=NULL;
                delete head;
                numElements--;
                return;
            }
            prev=head;
            head=head->next;
        }
        cout<<"Key Not Found!"<<endl;
        return;
    }
    ~HashTable()
    {
        for(int i=0;i<tableSize;i++)
        {
            delete buckets[i];///this calls destructor of this class i.e. hashnode
        }
    }
};
