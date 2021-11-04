#include<iostream>

using namespace std;

int main(){

int n;
cin >> n;
int mountain[n];
for(int i=0;i<n;i++) cin >> mountain[i];

int max=mountain[0];
for(int i=1;i<n;i++) if(mountain[i]>max) max=mountain[i];

for(int i=0;i<max;i++){
    for(int j=0;j<n;j++){
        for(int k=0;k<=mountain[j];k++){
            if(i+k==max) cout <<"/";
            else cout << " ";
        }
        for(int k=mountain[j];k>0;k--){
            if(i+k==max) cout <<"\\";
            else cout << " ";
        }
    }
    cout << endl;
}


}
