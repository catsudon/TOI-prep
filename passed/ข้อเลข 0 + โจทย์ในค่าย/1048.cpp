#include<iostream>

using namespace std;

int ham[40];
int vsham[40];

int main(){

int k,n,x,count;
cin >> k >> n;
int point=0;
for(int i=1;i<=n;i++){
    x = i;
    count=0;
    while(x>0){
      //  cout << "ham[" << count << "] = " << x%2 << endl;
        ham[count] = x%2;
        x/=2;
        count++;
    }
    for(int j=k-1;j>=0;j--){
      //  cout << ham[j] << " and  " << vsham[j] << endl;
        if(ham[j]!=vsham[j]){
            point++;
        }

        vsham[j] = ham[j];
    }
    //cout << point << endl;
}

cout << point;



}
