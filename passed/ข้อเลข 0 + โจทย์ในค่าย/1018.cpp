#include<iostream>

using namespace std;

int main(){

int n;
cin >> n;
long int x=0,y=0;
int direction = 1;
int go = 1;
string command;
int dis;
for(int i=0;i<n;i++){

    cin >> command;
    cin >> dis;
    if(command[0]=='R'){
        direction++;
        if(direction<0) direction =  4+direction;
    }
    if(command[0]=='L') {
        direction--;
        if(direction<0) direction =  4+direction;
    }
    if(command[0]=='B') {
        direction-=2;
        if(direction<0) direction =  4+direction;

    }

    if(direction==0) y+=dis;
    if(direction==1) x+=dis;
    if(direction==2) y-=dis;
    if(direction==3) x-=dis;

  //  cout << x << " : " << y << endl;

    if(x>=50000 || y>=50000 || x<= -50000 || y<= -50000){
        cout << "DEAD";
        return 0;
    }


}
if(go==1){
cout << x << " " << y << endl;

    if(direction==0) cout << "N";
    if(direction==1) cout << "E";
    if(direction==2) cout << "S";
    if(direction==3) cout << "W";
}




}
