#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

int main(){

int n;
cin >>n;
int table[n][n];
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cin >> table[i][j];
    }
}
// down
int sumdown[n];
for(int i=0;i<n;i++){
    sumdown[i]=0;
    for(int j=0;j<n;j++){
    sumdown[i]+=table[i][j];
    }
}

// right
int sumright[n];
for(int i=0;i<n;i++){
    sumright[i]=0;
    for(int j=0;j<n;j++){
    sumright[i]+=table[j][i];
    }
}
// tayeang
int tayeang1=0,tayeang2=0;
for(int i=0;i<n;i++){
    tayeang1+=table[i][i];
}

for(int i=0;i<n;i++){
    tayeang2+=table[i][n-i-1];
}

int a=1;
for(int i=1;i<n;i++){
   // cout << sumdown[i] << " " << sumdown[i-1]<< endl;
    if(sumdown[i]!=sumdown[i-1]){
    a=0;
    break;
    }
}

for(int i=1;i<n;i++){
    //cout << sumright[i] << " " << sumright[i-1] << endl;
    if(sumright[i]!=sumright[i-1]){
    a=0;
    break;
    }
}


if(tayeang1!=tayeang2){
    a=0;
}
if(tayeang1!=sumright[0]){
    a=0;
}

int nsq = n*n;
int arr[nsq];
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)
    arr[(i*n)+j] = table[i][j];
}

sort(arr,arr+nsq);
for(int i=1;i<nsq;i++){
    if(arr[i]==arr[i-1]) a=0;
}

a==1 ? cout << "Yes" : cout << "No";


}
