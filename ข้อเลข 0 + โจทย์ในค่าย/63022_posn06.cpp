#include<iostream>

using namespace std;

int main(){

int n,m;
cin >> n >> m;

int count[10] = {0,0,0,0,0,0,0,0,0,0};

for(int i=n;i<=m;i++){
    if(i>=100){
        count[i/100]++;
    }
    if(i>=10){
        count[(i/10)%10]++;
    }
    if(i>=1) count[i%10]++;
}

for(int i=0;i<10;i++){
    cout << i << " " << count[i];
    cout << endl;
}



}
