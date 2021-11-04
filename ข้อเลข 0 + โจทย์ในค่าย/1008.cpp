#include<bits/stdc++.h>

using namespace std;

int main(){

ios_base::sync_with_stdio(0); cin.tie(0);
int max=0;
int min=INT_MAX;
int n;
cin >> n;
int L[n],R[n];
int H[n];
for(int i=0;i<n;i++){

    cin >> L[i] >> H[i] >> R[i];

    if(R[i]>max) max=R[i];
    if(L[i]<min) min=L[i];
}

int overall[max];
for(int i=0;i<max;i++){
    overall[i]=0;
}

for(int i=0;i<n;i++){
for(int j=L[i];j<R[i];j++){
    if(overall[j]<H[i]) overall[j]=H[i];
    }
}

int height = overall[1];
cout << min << " "<< overall[min] << " ";
for(int i=min+1;i<max;i++){
    if(overall[i]!=height){
        cout << i << " " << overall[i] << " ";
        height = overall[i];
    }
}


cout << max << " " << 0;
}
