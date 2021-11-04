#include <stdio.h>

int main(){
    int pos = 1;
    char change[50];
    scanf("%s",&change);
    //printf("%c",change[1]);
    int len = strlen(change);
    for(int i=0;i<len;i++){
        if(change[i]=='A'){
            if(pos==1){
                pos++;
            }
            else if(pos==2){
                pos--;
            }
        }
        else if(change[i]=='B'){
            if(pos==2){
                pos++;
            }
            else if(pos==3){
                pos--;
            }
        }
        else if(change[i]=='C'){
            if(pos==1){
                pos=3;
            }
            else if(pos==3){
                pos=1;
            }
        }
    }
    printf("%d",pos);
}
