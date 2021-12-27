#include<bits/stdc++.h>
using namespace std;
string board[8] = {"........",
                   "........",
                   "........",
                   "...OX...",
                   "...XO...",
                   "........",
                   "........",
                   "........"
                  };
char player = 'X';
int checkx[8] = {0,2,2,2,0,-2,-2,-2}; // 3 o clock - > 1.5o clock
int checky[8] = {2,2,0,-2,-2,-2,0,2};
int middlex[8] = {0,1,1,1,0,-1,-1,-1};
int middley[8] = {1,1,0,-1,-1,-1,0,1};
void check(int x ,int y)
{
    char rival;
    player == 'X' ? rival = 'O' : rival = 'X';

    for(int i=0;i<8;++i)
    {
        int ax = x+checkx[i];
        int ay = y+checky[i];
        int mdx = x+middlex[i];
        int mdy = y+middley[i];
        if(ax < 0 or ay < 0 or ax >=8 or ay >=8) continue;
        if(board[ax][ay] == player and board[mdx][mdy] == rival) {board[mdx][mdy] = player; check(mdx,mdy);}
    }
}

int play(int x,int y)
{
    board[x][y] = player;
    for(int i=0;i<8;++i) for(int j=0;j<8;++j) if(board[i][j]==player) check(i,j);
    player=='X' ? player='O' : player = 'X';
}

int main()
{
    int n; cin >> n;
    while(n--)
    {
        int a,b; // b = char-'a'
        char t;
        cin >> t >> a;
        b = t-'a';
        play(a-1,b);
    }

    for(int i=0;i<8;++i) cout << board[i] << endl;
}
