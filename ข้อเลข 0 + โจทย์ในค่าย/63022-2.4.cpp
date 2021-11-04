#include<iostream>
#include<iomanip>

using namespace std;

int main(){

int mid,final;
cout << "Please enter your midterm score : ";
cin >> mid;
if(mid>100 || mid<0) return 0;
cout << "Please enter your final score : ";
cin >> final;
if(final>100 || final<0) return 0;

float avg = mid+final;
avg /= 2;
cout << fixed << setprecision(2) << "Your Score = " << avg << " %" << endl;

int a = (int)avg/10;

switch(a){

case 10:
case 9:
case 8:
    cout << "Grade = G, Good";
    break;
case 7:
case 6:
case 5:
    cout << "Grade = P , Pass";
    break;
default:
    cout << "Grade = F , Fail";

}



}
