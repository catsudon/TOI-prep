#include<iostream>

using namespace std;

int items[10000],itemcount=0;

int main(){

int n;
cin >> n;
char cmd;
int memo;
for(int i=0;i<n;i++){

cin >> cmd;
if(cmd=='P'){
    cin >> memo;
    items[itemcount] = memo;
    itemcount++;
}
else if(cmd=='Q'){
   // if(itemcount==0) cout << -1 << endl;
    //else {
        int max = -1;
        for(int i=0;i<itemcount;i++)
            if(max<items[i]) {
                max = items[i];
                memo = i;
            }
        cout << max << endl;
        items[memo] = -1;
       // itemcount--;
    //}
}


}




}
