#include<stdio.h>

int main(){

    int i,j,k;
    int n;
    scanf("%d",&n);
    float coordinates[n][2];
    for(i=0;i<n;i++){
        scanf("%f %f",&coordinates[i][0],&coordinates[i][1]);
    }

    float arealist[161700];
    int count = 0;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            for(k=j+1;k<n;k++){       //|x1y2 + x2y3 + x3y1 - y1x2 - y2x3 - y3x1|/2
                float area = (coordinates[i][0]*coordinates[j][1]) + (coordinates[j][0]*coordinates[k][1]) + (coordinates[k][0]*coordinates[i][1]);
                area = area - (coordinates[i][1]*coordinates[j][0]) - (coordinates[j][1]*coordinates[k][0]) - (coordinates[k][1]*coordinates[i][0]);
                if(area<0){
                    area = -area;
                }
                area = area/2;
                arealist[count] = area;
                count++;
            }
        }
    }
float max = 0;
for(int i=0;i<count;i++){
    if(arealist[i]>max){
        max = arealist[i];
    }
}
printf("%.3f",max);
}
