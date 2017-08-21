#include <iostream>
using namespace std;
void merge(int a[],int b[],int m,int n,int c[])
{
    int i=0,j=0,k=0;

    while(i<m && j<n)
    {
        if(a[i]<=b[j])
        {
            c[k++]=a[i];
            i++;
        }
        else
        {
            c[k++]=b[j];
            j++;
        }
    }
    while(i<m)
    {
        c[k++]=a[i++];
    }
    while(j<n)
    {
        c[k++]=b[j++];
    }
    /*for(k=0; k<m+n; k++)
    {
        cout<<c[k]<<" ";
    }*/
}
void mergesort(int a[],int size)
{
    if(size==1) return;
    int mid=size/2;
    int half1[50],half2[50];
    for(int i=0; i<mid; i++)
    {
        half1[i]=a[i];
    }
    for(int i=mid; i<size; i++)
    {
        half2[i-mid]=a[i];
    }
    mergesort(half1,mid);
    mergesort(half2,size-mid);
    merge(half1,half2,mid,size-mid,a) ;
}
int main()
{
    int a[50];
    int m;
    cout<<"Enter number of elements:";
    cin>>m;
    for(int i=0; i<m; i++)
    {
        cin>>a[i];
    }
    mergesort(a,m);
    for(int i=0; i<m; i++)
    {
        cout<<a[i]<<" ";
    }

}



