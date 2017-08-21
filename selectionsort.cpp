#include <iostream>
using namespace std;
void selectionSort(int a[],int n)
{
    for(int j=0; j<n-1; j++)
    {
        int min=a[j];
        int pos=j;
        for(int i=j+1; i<n; i++)
        {
            if(a[i]<=min)
            {
                min=a[i];
                pos=i;
            }
        }
        int temp=a[j];
        a[j]=min;
        a[pos]=temp;
    }
}
int main()
{
    int a[50];
    int n;
    cout<<"Enter number of elements:";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    selectionSort(a,n);
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }

}






