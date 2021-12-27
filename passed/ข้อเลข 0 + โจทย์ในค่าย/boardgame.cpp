#include<iostream>
using namespace std;

int n,m,point=0;


void brickbreak(char* board){

for(int i=0;i<n*m;i++){
    if(*(board+i)!='#' && *(board+i)!='-'){
        if(*(board+i+1)==*(board+i) && *(board+i)==*(board+i+m+1) && *(board+i)==*(board+i+m)){
            *(board+i+1) = '-';
            *(board+i)   = '-';
            *(board+i+m+1) = '-';
            *(board+i+m) = '-';
            point += 20;
        }
        else if(*(board+i+1)==*(board+i) && *(board+i)==*(board+i+m)){
            *(board+i+1) = '-';
            *(board+i)   = '-';
            *(board+i+m) = '-';
            point += 15;
        }
        else if(*(board+i+1)==*(board+i) && *(board+i)==*(board+i+m+1)){
            *(board+i+1) = '-';
            *(board+i)   = '-';
            *(board+i+m+1) = '-';
            point += 15;
        }
        else if(*(board+i+1)==*(board+i)){
            *(board+i+1) = '-';
            *(board+i)   = '-';
            point += 10;
        }
        else if(*(board+i+m) == *(board+i)){
            if(*(board+m-1)==*(board+i)){
                *(board+m-1) = '-';
                point+=5;
            }
            *(board+i+m) = '-';
            *(board+i)   = '-';
            point += 10;
        }
    }
}

}

void gravity(char* board){

for(int j=0;j<5;j++)
for(int i=n*m-1;i>=0;i--){
    if(*(board+i)!='#' && *(board+i)!='-'){
        if(*(board+i+m)=='-'){
            *(board+i+m) = *(board+i);
            *(board+i)   = '-';
        }
    }
}

}


main(){

cin >> n >> m;
char board[n][m];
for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
        cin >> board[i][j];

int cmdn;
cin >> cmdn;
gravity(&board[0][0]);
gravity(&board[0][0]);
gravity(&board[0][0]);
brickbreak(&board[0][0]);
int a,b;
char dir;
for(int i=0;i<cmdn;i++){

cin >> a >> b >> dir;
if(dir=='L'){
    if(board[a][b] != '-' && board[a][b] != '#' && board[a][b-1] == '-'){
        board[a][b-1] = board[a][b];
        board[a][b] = '-';
        for(int i=0;i<5;i++){
        gravity(&board[0][0]);
        gravity(&board[0][0]);
        gravity(&board[0][0]);
        brickbreak(&board[0][0]);
        }
    }
    else point-=5;
}

else if(dir=='R'){
    if(board[a][b] != '-' && board[a][b] != '#' && board[a][b+1] == '-'){
        board[a][b+1] = board[a][b];
        board[a][b] = '-';
        for(int i=0;i<5;i++){
        gravity(&board[0][0]);
        gravity(&board[0][0]);
        gravity(&board[0][0]);
        brickbreak(&board[0][0]);
        }
    }
    else point-=5;

}



}
cout << point << endl;
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++) cout << board[i][j] << " ";
cout << endl;
}

}
