#include<iostream>
#include<iomanip>

using namespace std;

int main(){

int a[20];
float sum=0,count=0;

for(int i=0;i<20;i++) {
    cin >> a[i];
    if(a[i]>0){
    sum+=a[i];
    count++;
    }
}

cout << fixed << setprecision(2) << sum/count;

}
