#include<iostream>
#include<string>

using namespace std;


int main(){

string a;
cout << "Input String = ";
cin >> a;
int start;
int ispalin = 0;

if(a.length()%2==1){
    int start = a.length()/2;
    if(start==1){
        if((int)a[start-1]==(int)a[start+1]){
            cout << a << " is palindrome";
            return 0;
        }
    }
    for(int i=1;i<start;i++){
        if((int)a[start-i]==(int)a[start+i]){
            ispalin=1;
        }
        else{
            cout << a << " is not a palindrome";
            return 0;
        }
    }

}
else{
    int start = a.length()/2;
    for(int i=0;i<start;i++){
        if((int)a[start-i-1]==(int)a[start+i]){
            ispalin=1;
        }
        else{
            cout << a << " is not a palindrome";
            return 0;
        }
    }
}


if(ispalin) cout << a << " is a palindrome";

}
