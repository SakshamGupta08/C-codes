#include<iostream>
using namespace std;
int subsequences(char input[],int startindex,char output[][50]){
if(input[startindex]=='\0'){
    output[0][0]='\0';
    return 1;
}
int size=subsequences(input,startindex+1,output);
for(int i=0;i<size;i++){
        output[i+size][0]=input[startindex];
        int j;
    for(j=0;output[i][j]!='\0';j++){
        output[i+size][j+1]=output[i][j];

    }
output[i+size][j+1]='\0';
}
return 2*size;
}

int main(){
char c[100];
cout<<"Enter string:";
cin>>c;
char output[50][50];
int size=subsequences(c,0,output);
for(int i=0;i<size;i++){
    cout<<output[i]<<endl;
}
}
