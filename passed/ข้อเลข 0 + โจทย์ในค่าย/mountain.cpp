#include<stdio.h>
int main(){
  int n, max=0;
  scanf("%d", &n);
  int height[n];
  for(int i=0;i<n;i++) {
    scanf("%d", &height[i]);
    if(height[i]>=max) max = height[i];
  }
  for(int i=0;i<max;i++) {
    for(int j=0;j<n;j++) {
      for(int k=0;k<height[j];k++){
           // printf("%d%d%d ",i,j,k);
           i+k==max-1 ? printf("/") : printf(" ");
      }
      for(int k=height[j]-1;k>=0;k--) i+k==max-1 ? printf("\\") : printf(" ");
    }
    printf("\n");
  }
  return 0;
}
