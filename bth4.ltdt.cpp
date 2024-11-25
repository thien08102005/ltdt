#include<iostream>
#include<queue>
#include<stdio.h>
int n,x,a[10][10],d[10],BFS[10],kq[10];
using namespace std;
void docfile()
{
	FILE *f;
	f = fopen("Dothi.txt","r");
	if(f==NULL)
		printf("Khong co tap tin!");
	else
	{
		fscanf(f,"%d",&n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				fscanf(f,"%d",&a[i][j]);
	}
	fclose(f);
}
int main(){
	docfile();
	printf("Nhap dinh x =");
  	scanf("%d",&x);
  	int t=0,kq;
	for(int i=n;i>0;i--)
	d[i]=0;
	queue<int> Q;
  	Q.push(x);
  	d[x]=1;
  	  while (!Q.empty())
		{
        kq=Q.front();
        Q.pop();
			{
			 BFS[t]=kq;
			 t++;
			}
	for(int i=1;i<=n;i++)
		 if(a[kq][i]!=0&&d[i]==0){
		 Q.push(i);
		 d[i]=1;
   		 }
		}
	for(int i=0;i<n;i++)
  	   printf("%d\t",BFS[i]);
}
