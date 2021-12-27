#include<stdio.h>

int main(){

int a,b;
int dwarf[9];
for(int i=0;i<9;i++){

    scanf("%d",&dwarf[i]);
}

for(int i=0;i<36;i++){

   for(int j=0;j<9;j++){
    for(int k=9;k>j;k--){
            int count=0;
        for(int l=0;l<9;l++){
            if(l!=j&&l!=k){
            count = count+dwarf[l];
            }

    }
            if(count==100){
            a=j;
            b=k;
            break;
        }
    }

   }
}
for(int i=0;i<9;i++){
    if(i!=a&&i!=b){
        printf("%d\n",dwarf[i]);
    }
}

}
