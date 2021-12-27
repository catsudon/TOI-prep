#include<iostream>
#include<string>

using namespace std;

int main(){

string a;
cout << "Please enter number : ";
cin >> a;
string number[10] = {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
int num = (int)a[a.length()-1];
cout << number[num-48];


}
