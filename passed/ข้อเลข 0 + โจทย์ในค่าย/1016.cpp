#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

int main(){

string command = "hello";
int x=0,y=0;
while(command[0]!='*'){
    cin >> command;
    if(command[0]=='*'){
        break;
    }
    else if(command[1]=='N') y+=command[0]-48;
    else if(command[1]=='S') y-=command[0]-48;
    else if(command[1]=='E') x+=command[0]-48;
    else if(command[1]=='W') x-=command[0]-48;

    }
double a = x*x,b = y*y;
double c = a+b;
c = sqrt(c);
cout << fixed << setprecision(3) << (float)x  <<" " << (float)y << endl;
cout << c;


}
