#include <iostream>
using namespace std;
int getStringLength(char c[])
{
    int len = 0;
    for(int i = 0; c[i] != '\0'; i++)
    {
        len++;
    }
    return len;
}
void swap(char x[], char y[])
{
    char temp[50];
    temp[0] = x[0];
    x[0] = y[0];
    y[0] = temp[0];
}
void permute(char a[], int l, int r)
{
    int i;
    if (l == r)
        cout<<a<<" ";
    else
    {
        for (i = l; i <= r; i++)
        {
            swap(a[l],a[i]);
            permute(a,l+1,r);
            swap(a[l],a[i]);
        }
    }
}
int main()
{
    char c[50];
    cout<<"Enter string:";
    cin>>c;
    int n=getStringLength(c);
    permute(c, 0, n-1);
}
