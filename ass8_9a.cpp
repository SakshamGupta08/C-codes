#include <iostream>
using namespace std;
void keypadhelper(int n,char c[])
{
    switch(n)
    {
    case 2:
    {
        c[0]='a';
        c[1]='b';
        c[2]='c';
        c[3]='\0';
        break;
    }
    case 3:
    {
        c[0]='d';
        c[1]='e';
        c[2]='f';
        c[3]='\0';
        break;
    }
    case 4:
    {
        c[0]='g';
        c[1]='h';
        c[2]='i';
        c[3]='\0';
        break;
    }
    case 5:
    {
        c[0]='j';
        c[1]='k';
        c[2]='l';
        c[3]='\0';
        break;
    }
    case 6:
    {
        c[0]='m';
        c[1]='n';
        c[2]='o';
        c[3]='\0';
        break;
    }
    case 7:
    {
        c[0]='p';
        c[1]='q';
        c[2]='r';
        c[3]='s';
        c[4]='\0';
        break;
    }
    case 8:
    {
        c[0]='t';
        c[1]='u';
        c[2]='v';
        c[3]='\0';
        break;
    }
    default:
    {
        c[0]='w';
        c[1]='x';
        c[2]='y';
        c[3]='z';
        c[4]='\0';
    }
    }
}

void printk(int n,char output[])
{
    if(n==0)
    {
        cout<<output<<" ";
        return;
    }
    char temp1[50];
    keypadhelper(n%10,temp1);
    for(int i=0; temp1[i]!='\0'; i++)
    {
        char temp2[50];
        temp2[0]=temp1[i];
        int j;
        for(j=0; output[j]!='\0'; j++)
        {
            temp2[j+1]=output[j];
        }


        temp2[j+1]='\0';

        printk(n/10,temp2);
    }
}


int main()
{
    int n;
    cout<<"Enter number:";
    cin>>n;
    char c[100];
    c[0]='\0';
    printk(n,c);
}






