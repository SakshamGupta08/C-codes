#include <iostream>
using namespace std;
int power(int x,int n){
    if(n==0)return 1;
    int ans=power(x,n-1);
    return x*ans;

}
int main()
{int n;
cout<<"Enter power:";
cin>>n;
int x;
cout<<"Enter base:";
cin>>x;
cout<<power(x,n)<<endl;
}


