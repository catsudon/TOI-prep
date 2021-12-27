#include<iostream>
#include<string>

using namespace std;

int main(){

    string a,b;
    char whattodo[1];
    cin >> a >> whattodo[0] >> b;
    int alen = a.length();
    int blen = b.length();
    int max = alen;
    int pontang = max-blen;
    if (blen>max) {
        max = blen;
        pontang = max-alen;
    }


    if(whattodo[0]=='+'){
        for(int i=0;i<max;i++){
            if(alen>=max-i && blen<max-i){
                cout<< a[i];
            //    cout << "frst " << endl;
            }
            else if(alen<max-i && blen>=max-i){
                cout << b[i];
             //   cout << "doub " << endl;
            }
            else if(alen>blen){
                if(a[i]=='1'&&b[i-pontang]=='1') cout << '2';
                if(a[i]=='0'&&b[i-pontang]=='1') cout << '1';
                if(a[i]=='1'&&b[i-pontang]=='0') cout << '1';
                if(a[i]=='0'&&b[i-pontang]=='0') cout << '0';
             //   cout << "else " << i << endl;
            }
            else if(alen==blen){
                if(a[i]=='1'&&b[i]=='1') cout << '2';
                if(a[i]=='0'&&b[i]=='1') cout << '1';
                if(a[i]=='1'&&b[i]=='0') cout << '1';
                if(a[i]=='0'&&b[i]=='0') cout << '0';
            }
            else{
                if(a[i-pontang]=='1'&&b[i]=='1') cout << '2';
                if(a[i-pontang]=='0'&&b[i]=='1') cout << '1';
                if(a[i-pontang]=='1'&&b[i]=='0') cout << '1';
                if(a[i-pontang]=='0'&&b[i]=='0') cout << '0';
            }
        }
    }
    else if(whattodo[0] =='*'){
        for(int i=0;i<alen;i++){
            cout << a[i];
        }
        for(int i=1;i<blen;i++){
            cout << 0;
        }
    }
}
