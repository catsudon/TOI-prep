#include<bits/stdc++.h>

using namespace std;
int g[500][500];
int m,n,c=0;
int countroom[20];
int coor=0,maxn=0;;


int start(int i,int j){

    if(g[i][j+1]==0){
        g[i][j+1] = 1;
        c+= 1+start(i,j+1);
    }
    if(g[i+1][j]==0){
        g[i+1][j] = 1;
        c+= 1+start(i+1,j);
    }
    if(g[i][j-1]==0){
        g[i][j-1] = 1;
        c+= 1+start(i,j-1);
    }
    if(g[i-1][j]==0){
        g[i-1][j] = 1;
        c+= 1+start(i-1,j);
    }

    return 0;

}

int main(){


scanf("%d %d",&m,&n);
for(int i=0;i<m;i++){
    for(int j=0;j<n;j++) {
        int x;
        scanf("%d",&g[i][j]);
    }
}

for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        if(g[i][j]==0){
            //start
            g[i][j]=1;
            c=1;
            start(i,j);
            countroom[coor] = c;
            coor++;
            if(c>maxn) maxn=c;

        }
    }
}


printf("%d\n%d",coor,maxn);



}
