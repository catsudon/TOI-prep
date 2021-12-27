#include<bits/stdc++.h>
using namespace std;

int main(){

    string text; cin >> text;
    int len = text.length();
    for(int i=0;i<5;i++){
    for(int x=0;x<len;x++){
        if(i==0&&x==0){
            printf("..#..");
        }
        else if(i==0&(x+1)%3==0){
            printf(".*..");
        }
        else if(i==0){
            printf(".#..");
        }
        else if(i==1&&x==0){
            printf(".#.#.");
        }
        else if(i==1&(x+1)%3==0){
            printf("*.*.");
        }
        else if(i==1){
            printf("#.#.");
        }

        else if(i==2&&x==0){
            printf("#.%c.#",text[x]);
        }
        else if(i==2&(x+1)%3==0){
            printf(".%c.*",text[x]);
        }
        else if(i==2&&(x+1)%3==2&&x+1!=len){
            printf(".%c.*",text[x]);
        }
        else if(i==2){
            printf(".%c.#",text[x]);
        }


        else if(i==3&&x==0){
            printf(".#.#.");
        }
        else if(i==3&(x+1)%3==0){
            printf("*.*.");
        }
        else if(i==3){
            printf("#.#.");
        }
        if(i==4&&x==0){
            printf("..#..");
        }
        else if(i==4&(x+1)%3==0){
            printf(".*..");
        }
        else if(i==4){
            printf(".#..");
        }
    }
    printf("\n");
    }

}
