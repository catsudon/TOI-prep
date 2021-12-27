#include<iostream>
#include<string>

using namespace std;

int main(){

string name,sur,gender;
cin >> name >> sur >> gender;

string fullname =  name + " " + sur;

gender=="Male"? cout << "Mr.":cout << "Mrs.";
cout << fullname;

}
