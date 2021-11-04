#include<iostream>

using namespace std;

int main(){

int n;
cin >> n;
int mount[n];
for(int i=0;i<n;i++) cin >> mount[i];
int max = mount[0];
for(int i=1;i<n;i++) if(mount[i]>max) max=mount[i];

for(int i=max;i>=0;i--){
    for(int j=0;j<n;j++){
        for(int k=0;k<mount[j];k++) k+i==max? cout << "\\" : cout << " ";
        for(int k=mount[j]-1;k>=0;k--) k+i==max? cout << "/" : cout << " ";
    }

cout << endl;
}





}
