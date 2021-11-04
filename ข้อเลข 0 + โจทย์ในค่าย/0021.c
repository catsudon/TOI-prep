#include<stdio.h>

int main(){

    char text[100];
    char newstr[100];
    gets(text);
    for(int i=0;i<100;i++){
        newstr[i]=' ';
    }
    int count=0;
for(int i=0;i<strlen(text);i++){
    if(text[i]=='a' || text[i]=='e' || text[i]=='i' || text[i]=='o' || text[i]=='u'){
            if( text[i]==text[i+2]  && text[i+1]=='p'){
            i+=2;
            newstr[count]=text[i];
            count++;
    }
    else{
        newstr[count]=text[i];
        count++;
    }
    }
    else{
        newstr[count]=text[i];
        count++;
    }
}
for(int i=0;i<count;i++){
    printf("%c",newstr[i]);
}
}
