#include<iostream>

using namespace std;

int main(){

int num[20];
for(int i=0;i<20;i++) cin >> num[i];

for(int i=0;i<19;i++){
    int count = 1;
    for(int j=i+1;j<20;j++){
        if(num[j]==num[i] && num[j]!=0){
            num[j]=0;
            count++;
        }
    }
    if(count>1) cout << num[i] << " " << count << endl;
}



}
