#include<iostream>

using namespace std;

int main(){

int korsor;
cout << "Input Christian Era: ";
cin >> korsor;
int porsor = korsor+543;
cout << "Change to Buddhist Era = = > " << porsor << endl;

cout << "Sum of A.D = " << korsor/1000 << " + " << (korsor/100) % 10 << " + " << (korsor%100)/10 << " + " << korsor%10 << " = " <<  korsor/1000+(korsor/100)%10+(korsor%100)/10+korsor%10 << endl;
cout << "Sum of B.E = " << porsor/1000 << " + " << (porsor/100) % 10 << " + " << (porsor%100)/10 << " + " << porsor%10 << " = " <<  porsor/1000+(porsor/100)%10+(porsor%100)/10+porsor%10;

}
