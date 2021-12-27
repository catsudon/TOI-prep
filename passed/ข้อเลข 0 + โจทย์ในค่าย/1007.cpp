#include<iostream>


using namespace std;

int main(){

int year[25];
int trash=0;
int counter = 0;
while(year[counter-1]!=-1){
    cin >> year[counter];
    counter++;
}

for(int i=0;i<counter-1;i++){
    int bee[3] = {1,1,0};
    for(int j=1;j<year[i]+1;j++){
        // tahan
        int loopcount = bee[2];
        int newborn =0;
        for(int k=0;k<loopcount;k++){
            bee[2]--;
            newborn++;
            bee[1]++;
        }
        for(int l=0;l<bee[1]-newborn;l++){
            bee[2]++;
        }
        bee[1]++;


    }
    cout << bee[1] << " " << bee[0]+bee[1]+bee[2];
    cout << endl;
}


}
