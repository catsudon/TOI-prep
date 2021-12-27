#include<iostream>

using namespace std;

int main(){

int a[3][2];
int b[3][2];

for(int i=0;i<3;i++)
    for(int j=0;j<2;j++)
    cin >> a[i][j];

int k;
for(int i=0;i<3;i++){
    for(int j=0;j<2;j++){
        cin >> k;
        cout << a[i][j]+k << " ";
    }
cout << endl;
}

}
