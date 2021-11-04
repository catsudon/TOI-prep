#include<iostream>
#include<iomanip>

using namespace std;

int main(){

int a,b,c,d;
cin >> a >> b >> c >> d;

if(a>100 || b>100 || c>100 || d>100){

    cout << "Invalid input!!";

}
else{

    float avg = a+b+c+d;
    avg/=4;
    cout << fixed << setprecision(2) << avg;

}



}
