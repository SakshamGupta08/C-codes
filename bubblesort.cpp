#include <iostream>
using namespace std;
void BubbleSort(int a[],int n)
{
    for(int k=n-1;k>=0;k--){
    for(int j=0,i=j+1;j<k; i++,j++)
    {
                if (a[j]>=a[i]){
                int temp=a[j];
                a[j]=a[i];
                a[i]=temp;            }
        }
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
    BubbleSort(a,n);
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }

}
