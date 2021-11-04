#include<iostream>
using namespace std;

int main(){

int n;
cin >> n;
int num[n][n];

for(int i=0;i<n;i++)
    for(int j=0;j<n;j++) cin >> num[i][j];

for(int i=0;i<n;i++)
    for(int j=0;j<n/2;j++){
        if(j<=i){
            int temp = num[i][j];
            num[i][j] = num[i][n-j-1];
            num[i][n-j-1] = temp;
        }
    }

for(int i=0;i<n;i++){
    for(int j=0;j<n;j++) cout << num[i][j] << " ";
    cout << endl;
}

}
