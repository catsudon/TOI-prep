#include<iostream>

using namespace std;

int main(){

int w,h,n;
cin >> w >> h >> n;
int a,b;
int window[w];
for(int i=0;i<w;i++){
    window[i]=0;
}

int count0 = w;
int count1 = 0;

for(int i=0;i<n;i++){
    cin >> a >> b;
    int loopcount = a+b;
    for(int j=a;j<loopcount;j++){
        if(window[j]==1 && j<w){
            window[j] = 2;
            count1--;
        }
        else if(window[j]==0 && j<w){
            window[j] = 1;
            count1++;
            count0--;
        }

    }
}

cout << count0*h << " " << count1*h;


}
