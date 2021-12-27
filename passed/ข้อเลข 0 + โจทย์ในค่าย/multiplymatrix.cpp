#include<iostream>

using namespace std;
int main(){

int m1[3][3] = {{1,2,3},{3,4,2},{3,2,1}};
int m2[3][3] = {{1,1,1},{3,4,2},{3,2,1}};
int ans[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
for(int i=0;i<3;i++)
{
    for(int j=0;j<3;j++){
        for(int k=0;k<3;k++){
            ans[i][j] += m1[i][k]*m2[k][j];
        }
    }


}

for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        cout << ans[i][j] << " ";
    }
    cout << endl;
}



}
