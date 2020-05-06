#include <stdio.h>
#include <stdlib.h>
#include <conio.h>



int main() 
{
	int n,k,i,j;
	printf("enter n: \n");
	scanf("%d", &n);
	printf("\n");
	int a[n],b[n];
	srand(time(NULL));
	for (i=0; i<n; i++)
	{
		a[i]=rand()%100;
	}
	for (i=0; i<n; i++)
	{
		printf("%3d", a[i]);
	}
	printf("\n\n");
	k=a[0];
	for(i=0; i<n; ++i)
	{
		if(k<a[i])
		{
			k=a[i];
		}
	}
	int c[k];
	for(i=0; i<=k; i++)
	{
		c[i]=0;
	}
	for(j=0; j<n; j++)
	{
		c[a[j]]=c[a[j]] +1;
	}
	for(i=1; i<=k; i++)
	{
		c[i]=c[i]+c[i-1];
	}
	for(j=n-1; j>=0; j--)
	{
		b[c[a[j]]-1]=a[j];
		c[a[j]]=c[a[j]]-1;
	}
	for (i=0; i<n; i++)
	{
		printf("%3d", b[i]);
	}	
	getch();
	return 0;
}
