#include<iostream>
#include<string>

using namespace std;

int main(){

string a;
cin >> a;
int count[10] = {0,0,0,0,0,0,0,0,0,0};
int len = a.length();

for(int i=0;i<len;i++){
    count[a[i]-48]++;
}

for(int i=0;i<len;i++){
    if(count[a[i]-48]!=0){
        cout << "'" << (int)a[i]-48 << "'" << " = " << count[a[i]-48] << endl;
        count[a[i]-48] = 0;
}
}

}
