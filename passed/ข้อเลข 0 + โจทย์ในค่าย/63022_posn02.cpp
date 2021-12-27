#include<iostream>
#include<string>

using namespace std;
int base;

int to10(string num,int dec){

int len = num.length();
int l=1;
for(int i=len-1;i>=0;i--){
    if(num[i]=='A')dec+=10*l;
    else if(num[i]=='B')dec+=11*l;
    else if(num[i]=='C')dec+=12*l;
    else if(num[i]=='D')dec+=13*l;
    else if(num[i]=='E')dec+=14*l;
    else if(num[i]=='F')dec+=15*l;
    else{
        dec+= (int(num[i])-48)*l;
    }
    l*=base;
}
return dec;
}

void tobase(int sum){

int ans[10000];
int count=0;
while(sum>0){
    ans[count] = sum%base;
    sum/=base;
    count++;
}

for(int i=count-1;i>=0;i--){
    if(ans[i]==10)cout << "A";
    else if(ans[i]==11)cout << "B";
    else if(ans[i]==12)cout << "C";
    else if(ans[i]==13)cout << "D";
    else if(ans[i]==14)cout << "E";
    else if(ans[i]==15)cout << "F";
    else{
        cout << ans[i];
    }
}


}



int main(){

int dec1=0,dec2=0;
string num1,num2;
cin >> base >> num1 >> num2;
dec1 = to10(num1,dec1);
dec2 = to10(num2,dec2);

int sum = dec1+dec2;
tobase(sum);

}
