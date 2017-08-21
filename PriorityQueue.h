#include <vector>
#include <utility>
using namespace std;

template <typename T>
class PriorityQueue
{
    vector< pair<int,T*> * > pq;

public:
    PriorityQueue()
    {
        pq.push_back(NULL);
    }

    int getSize()
    {
        return pq.size() -1;
    }

    bool isEmpty()
    {
        return getSize()==0;
    }

    T* max()
    {
        if(isEmpty())
        {
            return 0;
        }

        return pq[1]->second;
    }

    void insert(int priority,T* value)
    {
        pair<int,T*> *newPair=new pair<int,T*>(priority,value);
        pq.push_back(newPair);

        int currentchildindex=getSize();
        int parentindex=currentchildindex/2;
        while(currentchildindex>1)
        {
            pair<int,T*> *parent=pq[parentindex];
            pair<int,T*> *child=pq[currentchildindex];
            if(parent->first < child->first)
            {
                pq[parentindex]=child;
                pq[currentchildindex]=parent;
                currentchildindex=parentindex;
                parentindex=parentindex/2;
            }
            else break;
        }
    }







};
