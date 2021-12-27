#include <stdio.h>

int main(){

    int n;
    scanf("%d",&n);
    char ans[n];
    scanf("%s",ans);

//ADRIAN a b c a b c . . .
    char adrian[n];
    int adrianScore=0;
    for(int i=0;i<n;i++){
        if((i+1)%3==1){adrian[i]='A';}
        if((i+1)%3==2){adrian[i]='B';}
        if((i+1)%3==0){adrian[i]='C';}
    }
    for(int i=0;i<n;i++){
        if(ans[i]==adrian[i]){adrianScore++;}
    }
//bruno b a b c b a b c  . . .
    char bruno[n];
    int brunoScore=0;
    for(int i=0;i<n;i++){
        if((i+1)%4==1){bruno[i]='B';}
        if((i+1)%4==3){bruno[i]='B';}
        if((i+1)%4==0){bruno[i]='C';}
        if((i+1)%4==2){bruno[i]='A';}
    }
    for(int i=0;i<n;i++){
        if(ans[i]==bruno[i]){brunoScore++;}
    }

//goran cc aa bb ...
    char goran[n];
    int goranScore=0;
    for(int i=0;i<n;i++){
        if((i+1)%6==1){goran[i]='C';}
        else if((i+1)%6==2){goran[i]='C';}
        else if((i+1)%6==3){goran[i]='A';}
        else if((i+1)%6==4){goran[i]='A';}
        else if((i+1)%6==5){goran[i]='B';}
        else if((i+1)%6==0){goran[i]='B';}
    }
    for(int i=0;i<n;i++){
        if(ans[i]==goran[i]){goranScore++;
        }
    }
//printf("\nAd:%d\nBr:%d\nGo:%d",adrianScore,brunoScore,goranScore);
 /*   if(brunoScore==goranScore && goranScore==adrianScore){
        printf("%d\nAdrian\nBruno\nGoran",adrianScore);
    }
    if(adrianScore>brunoScore){
        if(adrianScore>goranScore){
            printf("%d\nAdrian",adrianScore);
        }
        else if(adrianScore==goranScore){
            printf("%d\nAdrian\nGoran",adrianScore);
        }
        else if(goranScore>adrianScore){
            printf("%d\nGoran",goranScore);
        }
    }
    else if(brunoScore>adrianScore){
        if(goranScore>brunoScore){
            printf("%d\nGoran",goranScore);
        }
        else if(brunoScore>goranScore){
            printf("%d\nBruno",brunoScore);
        }
        else if(brunoScore==goranScore){
            printf("%d\nBruno\nGoran",brunoScore);
        }
    }
    else if(brunoScore==adrianScore){
        printf("%d\nAdrian\nBruno",adrianScore);
    }*/

    int max = 0;
    if(adrianScore>max){
        max = adrianScore;
    }
    if(brunoScore>max){
        max = brunoScore;
    }
    if(goranScore>max){
        max = goranScore;
    }
    printf("%d\n",max);
    if(adrianScore==max){printf("Adrian\n");}
    if(brunoScore==max){printf("Bruno\n");}
    if(goranScore==max){printf("Goran\n");}
}
