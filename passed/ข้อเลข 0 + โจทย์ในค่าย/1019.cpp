#include<iostream>
#include<string>


using namespace std;

int main(){

string a,b;
cin >> a >> b;

int alen = a.length();
int blen = b.length();
int count;
int max = 0;
int loop = 0;
int iremem;
for(int i=0;i<alen;i++){
    for(int j=0;j<blen;j++){
        if(a[i]==b[j]){
            loop=1;
            count = 1;
            if(count>max) max=count;
            while(loop==1 && count+i<alen && count+j<blen){
                if(a[i+count]==b[j+count]){
                    count++;
                    if(count>max) {max=count;iremem = i;}
                }
                else{
                    loop=0;
                }
            }

        }

    }
}

for(int i=0;i<max;i++){
  //  cout << iremem+i <<endl;
    cout << a[iremem+i];
}


}
