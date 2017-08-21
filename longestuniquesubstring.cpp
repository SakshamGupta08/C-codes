#include <iostream>
#include <cstring>
using namespace std;

char *longestUniqueSubstring(char input[])
{

    int freq[256];
    for(int i=0 ; i<256; i++)
    {
        freq[i]=-1;
    }
    int start=0,len=0;
    int tempStart=0,tempLen=0;
    for (int i=0; i<strlen(input); i++)
    {
        int index=input[i];
        if(freq[index]==-1 || tempStart>freq[index])
        {
            freq[index]=i;
        }
        else
        {
            tempLen=i-tempStart;
            if(tempLen>len)
            {
                len=tempLen;
                start=tempStart;
            }
            tempStart=freq[index]+1;
            freq[index]=i;
        }
    }
    if(tempStart==0)
    {
        len=strlen(input);
    }
    if(tempLen>len)
    {
        len=tempLen;
        start=tempStart;
    }
    int l=len-start+1;
    char* output= new char[l];
    int j=0;
    for(int i=start; i<start + l; i++)
    {
        output[j++]=input[i];
    }
    output[j]='\0';
    return output;
}

void printNumbers(int numSoFar,int n)
{
    if(numSoFar>n) return;

    cout<<numSoFar<<endl;
    for(int i=0; i<=9; i++)
    {
        if(numSoFar>n)
        {
            break;
        }
        printNumbers(numSoFar*10+i,n);
    }
}

void printLexicographicOrder(int n)
{
    for(int i=0; i<=9; i++)
    {
        printNumbers(i,n);
    }
}

int main()
{

    int n;
    cout<<"Enter upper limit: " <<endl;
    cin>>n;
    printLexicographicOrder(n);

}
