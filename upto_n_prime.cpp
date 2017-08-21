#include<iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter n:";
    cin >> n;
    if (n<=2) {
        cout << "Invalid request" << endl;
        return 0;
    }
    else {
        cout << "2";
        int j=3;
        while (j<=n) {
            int i=2;
            while (i<j) {
                if (j%i==0) j=j+1;
                else i++;
                }
                cout << j;
                j=j+1;

            }
        }
    }
