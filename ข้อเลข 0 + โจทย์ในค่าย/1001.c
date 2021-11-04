#include<stdio.h>


char board[21][21];
int block[20];

int main(){

    int n,m;
    scanf("%d %d",&n,&m);
    int i,j,k;
    for(i=0;i<n;i++){
        scanf("%s",board[i]);
    }
    for(i=0;i<m;i++){
        scanf("%d",&block[i]);
    }

    for(j=0;j<m;j++){
        while(block[j]>0){
            for(i=0;i<n,board[i][j+1]!='.';i++){
                if(board[i][j]=='O' && j!=0){
                    board[i][j-1] = '#';
                    block[j]--;
                }
                else if(board[i][j]=='#' && j!=0){
                    board[i][j-1] = '#';
                    block[j]--;
                }
                else if(board[i][j]=='.' && )
                    {
                    board[i][j] = '#';
                    block[j]--;
                    printf("stuck here %d %d",j,i);
                }
                else{
                    printf("%c",board[j][i]);
                }

        }
        }
    }



    //show
    for(i=0;i<n;i++){
        printf("%s\n",board[i]);
    }


}
