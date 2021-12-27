#include<stdio.h>
#include<string.h>


typedef struct{

char name[20];
int score;
int goalwin;
int goallose;

}teamsb;





int main(){

teamsb team[4];
int score[4][4];
scanf("%s\n%s\n%s\n%s",team[0].name,team[1].name,team[2].name,team[3].name);
int i,j;
for(i=0;i<4;i++){
    team[i].score = 0;
    team[i].goallose = 0;
    team[i].goalwin = 0;
}

for(i=0;i<4;i++){
    scanf("%d %d %d %d",&score[i][0],&score[i][1],&score[i][2],&score[i][3]);
}




for(i=0;i<4;i++){
    for(j=0;j<4;j++){
            if(i!=j){
        if(score[i][j]>score[j][i]){
            team[i].score+=3;
        }
        else if(score[i][j]==score[j][i]){
            team[i].score+=1;
        }
            }

        team[i].goalwin += score[i][j];
        team[j].goallose += score[j][i];


    }
}




teamsb temp;
for(i=0;i<4;i++){
    for(j=i;j<4;j++){
        if(team[j].score>team[i].score){
            temp = team[i];
            team[i] = team[j];
            team[j] = temp;
        }
    }
}


for(i=0;i<4;i++){
    for(j=i;j<4;j++){
        if(team[i].score == team[j].score && i!=j){
            if(team[i].goalwin-team[i].goallose>team[j].goalwin-team[j].goallose){}
            else if(team[i].goalwin-team[i].goallose<team[j].goalwin-team[j].goallose){
                temp = team[i];
                team[i] = team[j];
                team[j] = temp;
            }
            else if(team[i].goalwin-team[i].goallose==team[j].goalwin-team[j].goallose){
                if(team[i].goalwin>team[j].goalwin){}
                else if(team[i].goalwin<team[j].goalwin){
                    temp = team[i];
                    team[i] = team[j];
                    team[j] = temp;
                }
            }
            }
        }
    }





for(i=0;i<4;i++){
    printf("%s %d\n",team[i].name,team[i].score);
}

}
