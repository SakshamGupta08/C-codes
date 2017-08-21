#include <iostream>
#include <unordered_map>//used for hashing
using namespace std;
void printIntersectonWithDuplicates(int a[],int b[],int n1,int n2){
    unordered_map<int,int>map;
    for(int i=0;i<n1;i++)
    {
        map[a[i]]+=1;
    }
    for(int i=0;i<n2;i++)
    {
        if(map.count(b[i])==1){
            if(map[b[i]>0){
                cout<<b[i]<<endl;
                map[b[i]]--;
            }
        }
    }
}
void printIntersecton(int a[],int b[],int n1,int n2){
    unordered_map<int,bool>map;
    for(int i=0;i<n1;i++){
        map[a[i]]=true;    ///overloaded by unordered_map,its equivalent to map.add(a[i],true)
    }
    for(int i=0;i<n2;i++)
    {
        if(map.count(b[i]==1)///equivalent to map.search with return type bool///wont work in case of duplicates
           {
               cout<<b[i]<<endl;
           }
    }
}
int main()
{

}
