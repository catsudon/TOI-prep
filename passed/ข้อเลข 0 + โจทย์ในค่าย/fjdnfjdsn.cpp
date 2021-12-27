#include<iostream>
#include<string>

using namespace std;

int main(){

string a,b;
cin >> a >> b;

int samea,sameb;

for(int i=0;i<a.length();i++){
    for(int j=0;j<b.length();j++){
        if(a[i]==b[j]) {
            samea=i;
            sameb=j;
            j=21930213;
            i=21930213;
            break;
        }
    }
}

for(int i=0;i<sameb;i++){
    for(int j=0;j<samea;j++)cout << " ";
cout << b[i] << endl;
}
for(int i=0;i<a.length();i++) cout << a[i];
cout << endl;
for(int i=sameb+1;i<b.length();i++){
    for(int j=0;j<samea;j++)cout << " ";
cout << b[i] << endl;
}





}
