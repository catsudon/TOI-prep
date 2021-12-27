#include<iostream>

using namespace std;

int main(){

string num;
int i,m3=0,m11=0;
for(i=0;i<num.lenght();i++)

if(num.lenght()%2==1){
    m11 = num[0];
    for(i=1;i<num.lenght();i++){
        i%2==1? m11 += num[i]*10 :m11+=num[i];
    }
}
else{
    for(i=0;i<num.lenght();i++){
        i%2==1? m11 += num[i]*10 :m11+=num[i];
    }
}

cout << m11;
}
