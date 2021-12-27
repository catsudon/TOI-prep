#include<iostream>

using namespace std;
int lengthz(string a){
int len=0;
while(a[len]!='\0'){
    len++;
}
return len;
}
int main(){

string a;
getline(cin,a);
int len = lengthz(a);
cout << len;


}
