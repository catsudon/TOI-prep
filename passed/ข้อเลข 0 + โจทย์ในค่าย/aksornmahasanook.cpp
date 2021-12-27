#include<iostream>
#include<string>

using namespace std;

int main(){

string a,b;
cin >> a >> b;

int len1 = a.length(),len2 = b.length();
char onaji;
int pos1,pos2;

for(int i=0;i<len1;i++){
    for(int j=0;j<len2;j++){
        if(a[i]==b[j]){
            onaji = a[i];
            pos1 = i,pos2 = j;
        }
    }
}

for(int i=0;i<pos2;i++){
    for(int j=0;j<pos1;j++) cout << " ";
    cout << b[i] << " ";
    cout << endl;
}
for(int i=0;i<len1;i++) cout << a[i];
cout << endl;
for(int i=pos2+1;i<len2;i++){
    for(int j=0;j<pos1;j++) cout << " ";
    cout << b[i] << " ";
    cout << endl;
}



}
