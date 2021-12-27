#include<iostream>
#include<math.h>
#include<iomanip>

int a,b;

using namespace std;
void tri(){

float x=0;
x+=b+a;
x+= sqrt(b*b+a*a);
cout << fixed << setprecision(0) << x;

}

int main(){

cin >> a >> b;
tri();


}
