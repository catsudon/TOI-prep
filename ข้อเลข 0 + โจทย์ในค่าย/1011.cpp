#include<iostream>

using namespace std;

int n,m;
int point =0;


int main(){


cin >> n >> m;
int i,j;
char field[n][m];
for(i=0;i<n;i++){
    for(j=0;j<m;j++){
        cin >> field[i][j];
    }
}

int cmd;
cin >> cmd;
char command[cmd][3];
for(i=0;i<cmd;i++){
        for(j=0;j<3;j++){
            cin >> command[i][j];
        }
}

cout << cmd;
for(i=0;i<cmd;i++){
        cout << command[i][2] << "commandi"<<endl;
    if(command[i][2]=='L'){
        //cout << command[i][0] << " " << command[i][1] << endl;
        int aa = command[i][0] - 48;
        int aaa = command[i][1] - 48;
        char a = field[aa][aaa];
        char b = field[aa][aaa-1];
        if(b=='-'){
            field[aa][aaa-1] = field[aa][aaa];
            field[aa][aaa] = '-';
        }
        else{
            point -= 5;
        }

    }
    if(command[i][2]=='R'){
        int aa = command[i][0] - 48;
        int aaa = command[i][1] - 48;
        char a = field[aa][aaa];
        char b = field[aa][aaa+1];
        cout << a << " " << b<< endl;
        if(b=='-'){
            field[aa][aaa+1] = a;
            field[aa][aaa] = '-';
        }
        else{
            point -= 5;
        }
    }
        for(int o=0;o<n;o++){//
    for(j=0;j<m;j++){
        cout << field[o][j] << ' ';
    }
    cout << endl;
}//

  //  gravity(field);
for(int k=0;i<n;i++){
   for(int j=0;j<m;j++){
        if(field[k][j]=='A' || field[k][j]=='B'){
            if(field[k+1][j]=='-'){
                field[k+1][j] = field[k][j];
                field[k][j] = '-';
                if(field[k+2][j]=='-'){
                    field[k+2][j] = field[k+1][j];
                    field[k+1][j] = '-';
                }
            }
        }
    }
}
    //chikakucheck();

for(int k=0;k<n;k++){
    for(int j=0;j<m;j++){
        if(field[k][j]=='A'){
            if(field[k+1][j]=='A' && k+1<n){
                point +=10;
                field[k+1][j] = '-';
                field[k][j] = '-';
            }
            else if(field[k][j+1]=='A' && j+1<m){
                point +=10;
                field[k][j+1] = '-';
                field[k][j] = '-';
            }
        }
        if(field[k][j]=='B'){
            if(field[k+1][j]=='B' && k+1<n){
                point +=10;
                field[k+1][j] = '-';
                field[k][j] = '-';
            }
            else if(field[k][j+1]=='B' && j+1<m){
                point +=10;
                field[k][j+1] = '-';
                field[k][j] = '-';
            }
        }
    }

}
for(int k=0;k<n;k++){
        cout << "saikou";
   for(int j=0;j<m;j++){
        if(field[k][j]=='A' || field[k][j]=='B'){
            if(field[k+1][j]=='-'){
                field[k+1][j] = field[k][j];
                field[k][j] = '-';
                if(field[k+2][j]=='-'){
                    field[k+2][j] = field[k+1][j];
                    field[k+1][j] = '-';
                }
            }
        }
    }
}
}
cout << point << endl;
for(i=0;i<n;i++){
    for(j=0;j<m;j++){
        cout << field[i][j] << ' ';
    }
    cout << endl;
}

}
