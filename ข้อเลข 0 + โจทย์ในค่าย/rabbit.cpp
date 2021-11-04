#include<iostream>

using namespace std;

int main(){

int month;
cin >> month;
unsigned long long int month0 = 0;
unsigned long long int month1 = 2;
unsigned long long int month2 = 0;


for(int i=1;i<=month;i++){
    int temp = month1;
    month1+=month0;
    month0=0;
    month0+=month2;
    month2+=temp;
    cout << "month " << i << " " << month0+month1+month2 << " rabbits" << endl;

}


}
