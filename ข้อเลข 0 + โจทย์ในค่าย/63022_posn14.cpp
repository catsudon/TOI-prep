#include<iostream>

using namespace std;

int main(){

int n[3][7];
for(int i=0;i<3;i++)
    for(int j=0;j<7;j++)
        cin >> n[i][j];

for(int i=0;i<5;i++){
    int x=0;
    for(int j=0;j<3;j++){
        x+= n[j][i] + n[j][i+1] + n[j][i+2];
    }
    cout << x << " ";
}

}
