#include<iostream>

using namespace std;
int year,month;
int daysinmonth[12]={31,28,31,30,31,30,31,31,30,31,30,31};

int main(){

cin >> month >> year;
if(month==2){
    if(year%4==3) cout << 29;
    else cout << 28;
}
else{
    cout << daysinmonth[month-1];
}



}
