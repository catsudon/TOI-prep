#include<bits/stdc++.h>
using namespace std;
//string board[8] = {"XXXXXXXX","XXXXXXXX","XXXXXXXX","XXXXXXXX","XXXXXXXX","XXXXXXXX","XXXXXXXX","XXXXXXXX"};
int targetx = 1;
int targety = 0;
int mx=INT_MAX;
int start(int x,int y,int c,bool vst[][8])
{
    vst[x][y]=true;
   // cout << c << " " << x << " " << y << endl;
    if(x==targetx && y==targety) {if(c<mx) mx=c;}
    if(c>mx) return 0;
    c++;
    if(x-1>=0 && y-2>=0 && !vst[x-1][y-2])start(x-1,y-2,c,vst);
    if(x-2>=0 && y-1>=0 && !vst[x-2][y-1])start(x-2,y-1,c,vst);
    if(x-2>=0 && y+1<8 && !vst[x-2][y+1])start(x-2,y+1,c,vst);
    if(x-1>=0 && y+2<8 && !vst[x-1][y+2])start(x-1,y+2,c,vst);

    if(x+1<8 && y-2>=0 && !vst[x+1][y-2])start(x+1,y-2,c,vst);
    if(x+2<8 && y-1>=0 && !vst[x+2][y-1])start(x+2,y-1,c,vst);
    if(x+2<8 && y+1<8 && !vst[x+2][y+1])start(x+2,y+1,c,vst);
    if(x+1<8 && y+2<8 && !vst[x+1][y+2])start(x+1,y+2,c,vst);
}

int main()
{

  //  board[1][5] ='O';
    bool vst[8][8];
    for(int i=0;i<8;++i) for(int j=0;j<8;++j) vst[i][j]=0;
    start(5,4,0,vst);
    cout << mx;
}
