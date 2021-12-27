#include<iostream>

using namespace std;

int main(){

int r1,r2,c1,c2;
cin >> r1 >> c1 >> r2 >> c2;
r1=1;
c1=3;
r2=3;
c2=4;
int matrix1[r1][c1]={{3,4,2}};
int matrix2[r2][c2]={{13,9,7,15},{8,7,4,6},{6,4,0,3}};
int ans[r1][c2];
if(c1!=r2) {
    cout << "Not multiplyable";
    return 0;
}

for(int i=0;i<1;i++){
    for(int j=0;j<4;j++){
        ans[i][j]=0;
    }
}

for(int i=0;i<1;i++){
    for(int j=0;j<4;j++){
        for(int k=0;k<4;k++){
            ans[i][j] += matrix1[i][k]*matrix2[k][j];
        }
    }
}


for(int i=0;i<r1;i++){
    for(int j=0;j<c2;j++){
        cout << ans[i][j] << " ";
    }
    cout << endl;
}

}
