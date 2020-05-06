#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


void mergesort(int a[],int left,int right);
void merge(int a[],int l1,int l2,int r1,int r2);
 
int main()
{
    int n,i;
    printf("Enter n: ");
    scanf("%d",&n);                          // задаем размер массива
	int a[n];
	srand(time(NULL));
	for (i=0; i<n; i++)
	{
		a[i]=rand()%100;                        // создаем рандомный набор элементо в массиве
	}
	for (i=0; i<n; i++)
	{
		printf("%3d", a[i]);
	}
	printf("\n\n");
    mergesort(a,0,n-1);
    for(i=0;i<n;i++)
    {
    	printf("%3d ",a[i]);                           // выводим массив
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
        mergesort(a,left,m);                       //левая рекурсия 
        mergesort(a,m+1,right);                                    // правая рекурсия 
        merge(a,left,m,m+1,right);                                            //слияние двух отсортированных подмассивов
    }
}


void merge(int a[],int l1,int l2,int r1,int r2)
{
    int temp[r2];                        // массив, используемый для слияния
    int left,right,k;
    left=l1;                                                           // начало первого списка
    right=r1;                                                                         // начало второго списка
    k=0;
    while((left<=l2) && (right<=r2))                             // до тех пор, пока элементы в обоих списках
    {
        if(a[left]<a[right])
            temp[k++]=a[left++];
        else
            temp[k++]=a[right++];
    }
    while(left<=l2)                           //копируем оставшиеся элементы первого списка
    {
    	temp[k++]=a[left++];
	} 
    while(right<=r2)                                                  // копируем оставшиеся элементы второго списка
    {
    	temp[k++]=a[right++];
	}
    for(left=l1,right=0;left<=r2;left++,right++)          // Перенесите элементы из temp  обратно в а
    {
    	a[left]=temp[right];	
	}      
}
