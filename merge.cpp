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
    for(k=0; k<m+n; k++)
    {
        cout<<c[k]<<" ";
    }
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
    int b[50];
    int n;
    cout<<"Enter number of elements:";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>b[i];
    }
    int c[50];
    merge(a,b,m,n,c);
}






