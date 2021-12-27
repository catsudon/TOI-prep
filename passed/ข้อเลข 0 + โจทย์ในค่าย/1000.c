#include<stdio.h>

int main(){

int l,n;
scanf("%d",&l);
scanf("%d",&n);
char *word[n][l];

for(int i=0;i<n;i++){
        for(int j=0;j<l;j++){
            scanf("%c",&word[i][j]);
        }

  //  if(i>0)
   // printf("word i %s\n",word[i-1]);
}

char sakikotoba[l];
char imanokotoba[l];
for(int i=1;i<n;i++){
        int ten = 0;
    for(int j=0;j<l;j++){
        sakikotoba[j] = word[i-1][j];
        imanokotoba[j] = word[i][j];
        if(sakikotoba[j]==imanokotoba[j]){

        }
        else if(sakikotoba[j]!=imanokotoba[j]){
            ten++;
            //
            printf("\n%c from %s : %c from %s\n",sakikotoba[j],word[i-1],imanokotoba[j],word[i]);
            if(ten==3){
                printf("%s",word[i]);
                break;
            }
        }
    }
}
}
