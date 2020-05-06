#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void obminsort(int a[], int n) 
{
	int i,r,k,temp;
	r=n-1;
	while(r>0)
	{
		k=0;
		for(i=0; i<=r; i++)
		{
			if(a[i]>a[i+1])
			{
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;	
				k=i;
			}
		}
		r=k-1;
	}
	for (i=0; i<n; i++)
	{
		printf("%3d", a[i]);	
	}	
}
