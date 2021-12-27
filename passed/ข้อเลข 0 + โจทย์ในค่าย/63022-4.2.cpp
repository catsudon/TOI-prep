#include<iostream>

using namespace std;

int main(){

int n=0;
int max = 0;
int min = 100;
int sum = 0;
int count = 0;
while(n>=0 && n<=100){
    cin >> n;
    if(n>=0 && n<=100){
        if(n<min) min = n;
        if(n>max) max = n;
        sum += n;
        count++;
    }
}

cout << max << " " << min << " " << sum << " " << sum/count;



}
