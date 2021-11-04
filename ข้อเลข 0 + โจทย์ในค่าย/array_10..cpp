#include<iostream>

using namespace std;

int main(){

int n;
cin >> n;
int numbers[n];
int count[10] = {0,0,0,0,0,0,0,0,0,0};
for(int i=0;i<n;i++){
    cin >> numbers[i];
    count[numbers[i]]+=1;
}
int max = 0;
int x;
for(int i=0;i<10;i++){
    if(count[i]>max) {
        max = count[i];
        x = i;
    }
}
cout << "Mode is " << max;
for(int i=x+1;i<10;i++){
    if(count[i]==max) cout << " and " << i;
}

}
