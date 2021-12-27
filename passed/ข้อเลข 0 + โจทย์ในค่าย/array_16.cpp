#include<iostream>

using namespace std;

int main(){

int n[4][4];
for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
    cin >> n[i][j];

int sum=0;
for(int i=0;i<4;i++){
    for(int j=i+1;j<4;j++) sum+=n[i][j];
}

cout << sum;

}
