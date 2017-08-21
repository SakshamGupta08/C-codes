//Templates allow us flexibility of data type. Even two template types can be used.eg.<typename T,typename V>
template <typename T>
class myPair
{
    T first;
    T second;

public:
    /*myPair(T a,T b)
    {
        first=a;
        second=b;
    }
    */
    T getFirst()
    {
        return first;
    }
    void setFirst(T a)
    {
        first=a;
    }

    T getSecond()
    {
        return second;
    }
    void setSecond(T a)
    {
        second=a;
    }

