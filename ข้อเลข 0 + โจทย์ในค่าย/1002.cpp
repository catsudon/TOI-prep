#include<iostream>

using namespace std;

int main(){

int d;
cin >> d;
int ivxlc[5]={0,0,0,0,0};

int i;
for(i=1;i<d+1;i++){
    int num = i;
    while(num!=0){
    if(num>=100){
        ivxlc[4]+=1;
        num-=100;
    }
    else if(num>=90){
        ivxlc[2]+=1;
        ivxlc[4]+=1;
        num-=90;
    }
    else if(num>=50){
        ivxlc[3]+=1;
        num-=50;
    }
    else if(num>=40){
        ivxlc[2]+=1;
        ivxlc[3]+=1;
        num-=40;
    }
    else if(num>=10){
        ivxlc[2]+=1;
        num-=10;
    }
    else if(num>=9){
        ivxlc[0]+=1;
        ivxlc[2]+=1;
        num-=9;
    }
    else if(num>=5) {
        ivxlc[1]+=1;
        num-=5;
        }
    else if(num>=4){
        ivxlc[1]+=1;
        ivxlc[0]+=1;
        num-=4;
    }
    else if(num>=1){
        ivxlc[0]+=1;
        num-=1;
    }

    }
}

for(i=0;i<5;i++){
    cout << ivxlc[i] << " ";
}
}
