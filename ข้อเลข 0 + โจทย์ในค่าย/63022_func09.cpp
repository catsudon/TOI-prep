#include<math.h>
#include<iostream>
#include<iomanip>
#define PI 3.14159265

using namespace std;

int main(){

cout << "sin              cos              tan" << endl;
for(int i=0;i<90;i=i+5){
    cout << fixed << setprecision(4) << sin(i*PI/180) << "           " << cos(i*PI/180) << "           " << tan(i*PI/180) << endl;
}


}
