#include<iostream>
#include<string>
using namespace std;

int main(){

int n;
int temp[6];
cin >> n;
string move[n];
int face[n];
for(int i=0;i<n;i++){
cin >> move[i];

int dice[6] = {1,2,3,5,4,6};
for(int j=0;j<move[i].length();j++){
    if(move[i][j]=='F'){
        temp[0] = dice[0];temp[1] = dice[1];temp[2] = dice[2];temp[3] = dice[3];temp[4] = dice[4];temp[5] = dice[5];
        dice[0] = temp[3];
        dice[1] = temp[0];
        dice[3] = temp[5];
        dice[5] = temp[1];
    }
    if(move[i][j]=='B'){
        temp[0] = dice[0];temp[1] = dice[1];temp[2] = dice[2];temp[3] = dice[3];temp[4] = dice[4];temp[5] = dice[5];
        dice[0] = temp[1];
        dice[1] = temp[5];
        dice[3] = temp[0];
        dice[5] = temp[3];
    }
    if(move[i][j]=='L'){
        temp[0] = dice[0];temp[1] = dice[1];temp[2] = dice[2];temp[3] = dice[3];temp[4] = dice[4];temp[5] = dice[5];
        dice[0] = temp[4];
        dice[2] = temp[0];
        dice[4] = temp[5];
        dice[5] = temp[2];
    }
    if(move[i][j]=='R'){
        temp[0] = dice[0];temp[1] = dice[1];temp[2] = dice[2];temp[3] = dice[3];temp[4] = dice[4];temp[5] = dice[5];
        dice[0] = temp[2];
        dice[2] = temp[5];
        dice[4] = temp[0];
        dice[5] = temp[4];
    }
    if(move[i][j]=='C'){
        temp[0] = dice[0];temp[1] = dice[1];temp[2] = dice[2];temp[3] = dice[3];temp[4] = dice[4];temp[5] = dice[5];
        dice[1] = temp[4];
        dice[2] = temp[1];
        dice[3] = temp[2];
        dice[4] = temp[3];
    }
    if(move[i][j]=='D'){
        temp[0] = dice[0];temp[1] = dice[1];temp[2] = dice[2];temp[3] = dice[3];temp[4] = dice[4];temp[5] = dice[5];
        dice[1] = temp[2];
        dice[2] = temp[3];
        dice[3] = temp[4];
        dice[4] = temp[1];
    }
}

    face[i] = dice[1];
}

for(int i=0;i<n;i++){
    cout << face[i] << " ";
}

}
