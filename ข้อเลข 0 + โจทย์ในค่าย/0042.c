#include<stdio.h>
int main()
{
int n,q[20];
long double ans[20];
scanf("%d",&n);
for(int i=0;i<n;i++)
{
scanf("%d",&q[i]);
ans[i]=1.0;
for(int j=0;j<q[i];j++)
{
ans[i]*=2.0;
}

}
for(int i=0;i<n;i++)
{
printf("%.0Lf\n",ans[i]);
}
return 0;
}
