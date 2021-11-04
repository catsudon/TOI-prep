#include<bits/stdc++.h>

using namespace std;
pair<int,int> g[500][500];
int m,n,c;
int countroom[20];
int coor=0,maxn=0;;


int start(int i,int j){

    if(g[i][j+1].first==0 && g[i][j+1].second==0 && g[i+1][j].first==0 && g[i+1][j].second==0){
        g[i][j+1].second = 1;
        g[i+1][j].second = 1;
        return 2+start(i+1,j)+start(i,j+1);
    }
    else if(g[i][j+1].first==0 && g[i][j+1].second==0){
        g[i][j+1].second = 1;
        return 1+start(i,j+1);
    }
    else if(g[i+1][j].first==0 && g[i+1][j].second==0){
        g[i+1][j].second = 1;
        return 1+start(i+1,j);
    }

}

int main(){


scanf("%d %d",&m,&n);
for(int i=0;i<m;i++){
    for(int j=0;j<n;j++) {
        int x;
        scanf("%d",&x);
        g[i][j] = {x,0};
    }
}

for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        if(g[i][j].first==0 && g[i][j].second==0){
            //start
            c=start(i,j);
            printf("%d ",c);
            countroom[coor] = c;
            coor++;
            if(c>maxn) maxn=c;

        }
    }
}

printf("\n%d\n%d",coor,maxn);



}
