#include<iostream>
#include<iomanip>

using namespace std;

int main(){

int number[5],max,min;
float sum;
cin >> number[0];
max =  min =  sum = number[0];

for(int i=1;i<5;i++){
    cin >> number[i];
    if(number[i]>max) max = number[i];
    if(number[i]<min) min = number[i];
    sum += number[i];
}

cout << fixed << setprecision(2) << sum/5 << endl;
cout << max << " " << min;




}
