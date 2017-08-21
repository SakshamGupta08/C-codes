#include <iostream>
using namespace std;
int partitionArray(int a[],int startindex,int endindex)
{
    int count=0;
    int pivot=a[startindex];
    for(int i=startindex+1; i<=endindex; i++)
    {
        if(a[i]<pivot)
        {
            count++;
        }
    }
    int pivotindex=count+startindex;
    a[startindex]=a[pivotindex];
    a[pivotindex]=pivot;
    int j=endindex;
    int i=startindex;
    while(i<j)
    {
        while(a[i]<pivot)
        {
            i++;
        }
        while(a[j]>=pivot)
        {
            j--;
        }
        if(i<j)
        {
            int temp2=a[i];
            a[i]=a[j];
            a[j]=temp2;
        }
        i++;
        j--;

    }
    return pivotindex;
}
void quicksort(int input[],int startindex,int endindex)
{
    if(startindex>=endindex) return;
    int pivotindex=partitionArray(input,startindex,endindex);
    quicksort(input,startindex,pivotindex-1);
    quicksort(input,pivotindex+1,endindex);
}

int main()
{
    int input[50];
    int n;
    cout<<"Enter number of elements:";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>input[i];
    }
    cout<<"Sorted array is:";
    quicksort(input,0,n-1);
    for(int j=0; j<n; j++)
    {
        cout<<input[j];
    }
}

