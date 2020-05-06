#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


void mergesort(int a[],int left,int right);
void merge(int a[],int l1,int l2,int r1,int r2);
 
int main()
{
    int n,i;
    printf("Enter n: ");
    scanf("%d",&n);                          // ������ ������ �������
	int a[n];
	srand(time(NULL));
	for (i=0; i<n; i++)
	{
		a[i]=rand()%100;                        // ������� ��������� ����� �������� � �������
	}
	for (i=0; i<n; i++)
	{
		printf("%3d", a[i]);
	}
	printf("\n\n");
    mergesort(a,0,n-1);
    for(i=0;i<n;i++)
    {
    	printf("%3d ",a[i]);                           // ������� ������
	} 
    getch();
    return 0;
}


void mergesort(int a[],int left,int right)
{
    int m; 
    if(left<right)
    {
        m=(left+right)/2;
        mergesort(a,left,m);                       //����� �������� 
        mergesort(a,m+1,right);                                    // ������ �������� 
        merge(a,left,m,m+1,right);                                            //������� ���� ��������������� �����������
    }
}


void merge(int a[],int l1,int l2,int r1,int r2)
{
    int temp[r2];                        // ������, ������������ ��� �������
    int left,right,k;
    left=l1;                                                           // ������ ������� ������
    right=r1;                                                                         // ������ ������� ������
    k=0;
    while((left<=l2) && (right<=r2))                             // �� ��� ���, ���� �������� � ����� �������
    {
        if(a[left]<a[right])
            temp[k++]=a[left++];
        else
            temp[k++]=a[right++];
    }
    while(left<=l2)                           //�������� ���������� �������� ������� ������
    {
    	temp[k++]=a[left++];
	} 
    while(right<=r2)                                                  // �������� ���������� �������� ������� ������
    {
    	temp[k++]=a[right++];
	}
    for(left=l1,right=0;left<=r2;left++,right++)          // ���������� �������� �� temp  ������� � �
    {
    	a[left]=temp[right];	
	}      
}
