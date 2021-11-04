#include<iostream>

using namespace std;

int main(){

int n;
cin >> n;
int height[n];
int max=0;
for(int i=0;i<n;i++) {
    cin >> height[i];
    if(height[i]>max) max=height[i];
}


for(int i=max;i>0;i--){
    for(int j=0;j<n;j++){
        for(int k=0;k<height[j];k++) k+i==max ? cout << "\\" : cout << " ";
        for(int k=height[j];k>0;k--) k+i==max+1 ? cout << "/" : cout << " ";

    }
    cout << endl;
}

}
