//
#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#define N 100
int n,v[N],m[N][N][2];
char op[N]; 
void MinMax(int n,int i,int k,int j,int &minf,int &maxf)
{//最大值和最小值 
	int e[5],r;
	int a=m[i][k][0],b=m[i][k][1];
	r=(i+k-1)%n+1;
	int c=m[r][j-k][0],d=m[r][j-k][1];
	if(op[k-1]=='+')
	{
		minf=a+c;
		maxf=b+d;
	}
	else
	{
		e[1]=a*c;
		e[2]=a*d;
		e[3]=b*c;
		e[4]=b*d;
		minf=e[1];
		maxf=e[1];
		for(int t=2;t<=4;t++)
		{
			if(maxf<e[t])
			{
				maxf=e[t];
			}
			if(minf>e[t])
			{
				minf=e[t];
			}
		}
	}
}
int main()
{
	int i,j,k,minf,maxf;
	printf("请输入多边形顶点数：");
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
	{
		printf("请输入第%d条边的操作数和运算符：",i);
		scanf("%d %c",&v[i],&op[i]);
		m[i][1][0]=v[i];
		m[i][1][1]=v[i];
	} 
	for(j=2;j<=n;j++)
	{ 
		for(i=1;i<=n;i++)
		{
			for(k=1;k<=j-1;k++){
				MinMax(n,i,k,j,minf,maxf);
				if(m[i][j][0]>minf)
				{
					m[i][j][0]=minf;
				}
				if(m[i][j][1]<maxf){
					m[i][j][1]=maxf;
				}
			}
		}
	}
	int temp=m[1][n][1],p=1;
	for(i=2;i<=n;i++)
	{
		if(m[i][n][1]>temp){
			temp=m[i][n][1];
			p=i;
		}
	}
	printf("首断链位置为：%d,最大得分为：%d\n",p,temp);
	return 0;
}
