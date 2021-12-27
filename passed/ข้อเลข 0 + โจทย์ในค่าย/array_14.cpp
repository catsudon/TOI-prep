#include<iostream>

using namespace std;

int main(){

int num[5][3];
for(int i=0;i<5;i++){
    for(int j=0;j<3;j++){
        cin >> num[i][j];
    }
}

cout << "sum of each rows  : ";
for(int i=0;i<5;i++){
    int sum=0;
    for(int j=0;j<3;j++){
        sum+=num[i][j];
    }
    cout << sum << " ";
}
cout << endl << "sum of each columns : ";
for(int i=0;i<3;i++){
    int sum=0;
    for(int j=0;j<5;j++){
        sum+=num[j][i];
    }
    cout << sum << " ";
}




}
