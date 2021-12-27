#include <stdio.h>

#include <string.h>

typedef struct

{

    char name[21];

    int score;

    int goalWin;

    int goalLose;

}teamsb;



int main()

{

    teamsb team[4];          //ข้อมูลแต่ละทีม

    char tempc[21]=" ";     //ใช้ตอน Swap ตัวอักษรเพื่อจัดอันดับ

    int table[4][4];              //ตารางคะแนน 4x4

    int i,j,tempi;                 //counter, Swap ตัวเลขเพื่อจัดอันดับ



    for (i = 0; i < 4; i++)

    {

        team[i].score = 0;

        team[i].goalWin = 0;

        team[i].goalLose = 0;

    }



    scanf("%s",team[0].name);

    scanf("%s",team[1].name);

    scanf("%s",team[2].name);

    scanf("%s",team[3].name);



    for (i = 0; i < 4; i++)

    {

        scanf("%d %d %d %d",&table[i][0],&table[i][1],&table[i][2],&table[i][3]);

    }



    for (i = 0; i < 4; i++)

    {

        for (j = 0; j < 4; j++)

        {

            if (i != j)

            {

                team[i].goalWin += table[i][j];          //นับประตูได้-เสีย

                team[i].goalLose += table[j][i];

                team[j].goalWin += table[j][i];

                team[j].goalLose += table[i][j];



                if (table[i][j] == table[j][i] && i < j)    //คะแนนเสมอ

                {

                    team[i].score += 1;

                    team[j].score += 1;

                }

                else if (table[i][j] > table[j][i])          //คะแนนชนะ (แพ้ได้ 0 ไม่ทำอะไร)

                {

                    team[i].score += 3;

                }

            }

        }

    }



    for (i = 0; i < 3; i++)         //เรียงข้อมูลตามเงื่อนไข

    {

        for (j = 3; j >= i; j--)

        {

            if (team[i].score < team[j].score)

            {

                tempi = team[i].score;

                team[i].score = team[j].score;

                team[j].score = tempi;



                strcpy(tempc,team[i].name);

                strcpy(team[i].name,team[j].name);

                strcpy(team[j].name,tempc);

            }

            else if (team[i].score == team[j].score)

            {

                if (team[i].goalWin-team[i].goalLose < team[j].goalWin-team[j].goalLose)

                {

                    strcpy(tempc,team[i].name);

                    strcpy(team[i].name,team[j].name);

                    strcpy(team[j].name,tempc);

                }

                else if (team[i].goalWin-team[i].goalLose == team[j].goalWin-team[j].goalLose)

                {

                    if (team[i].goalWin < team[j].goalWin)

                    {

                        strcpy(tempc,team[i].name);

                        strcpy(team[i].name,team[j].name);

                        strcpy(team[j].name,tempc);

                    }

                }

            }

        }

    }



    for (i = 0; i < 4; i++)

    {

        printf("%s %d\n",team[i].name,team[i].score);

    }

    return 0;

}
