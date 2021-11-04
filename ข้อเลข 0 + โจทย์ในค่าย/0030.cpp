#include<iostream>
#include<string>

using namespace std;

int main(){

string num;
cin >> num;
int i,m3=0,m11=0;
for(i=0;i<num.length();i++)

if(num.length()%2==1){
    m11 = (int)num[0]-48;
    for(i=1;i<num.length();i++){
        int a = (int)num[i]-48;
        i%2==1? m11 += a*10 :m11+=a;
    }
}
else{
    for(i=0;i<num.length();i++){
        int a = (int)num[i]-48;
        i%2==0? m11 += a*10 :m11+=a;
    }
}
for(i=0;i<num.length();i++){
    int a = (int)num[i]-48;
    m3 += a;
}
cout << m3%3 << " " <<m11%11;
}
