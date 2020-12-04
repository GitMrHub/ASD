#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


void obminsort(int a[], int n);
void merge(int a[],int l1,int l2,int r1,int r2);
void mergesort(int a[],int left,int right);
void pidrahynokSort(int a[], int n);


double ch = 0;                //Number of changes
double eq = 0;				  //Number of equals
	
	
int main() 
{
  	int i, j, n, choice_1, choice_2, k;
  	printf("Input size of matrix: ");
 	scanf("%d", &n);
  	int a[n];
  	
  	printf("\nHow do enerate array: \n");
  	printf("1 - generate random elements \n");          //random
  	printf("2 - worst case \n");                       // 100000.. to 2,1
  	printf("3 - best case \n");                       // 1,2 to 100000
  	scanf("%d", &choice_1);
  	
  	srand(time(NULL));	
  	switch(choice_1)
  	{
  		case(1):
		  for (i=0; i<n; i++)
			{
			a[i] = 0 + rand() %100;
			}
  			break;
  		
  		case(2):
	  	    for (i=0, k=n; i<n; i++, k--)
  			{
				a[i] = k;			
 			}
			break;
		
		case(3):
	  	  for (i=0; i<n; i++)
  			{
      			a[i] = i;
 			}
			break;
			
		default:
			printf("Error");
			break;
	}
  	                                  	//output      çàêîìåíò ïðè áîëüøèõ çíà÷åíèÿõ n
  	
  	printf("\n");
	for (i = 0; i<n; i++)  
	{
      printf("%7d ", a[i]);
  	}
    printf("\n");
	
	                                  		 //Choose the sort
 	printf("\nChoose the sort: \n");
  	printf("1 - Obmin Sort \n");
  	printf("2 - Pidrahynok Sort \n");
  	printf("3 - Merge Sort \n");
  	
	scanf("%d", &choice_2);		
  	switch(choice_2)
  	{
  		case(1):
  			obminsort(a, n);
			break;
			
		case(2):
  			pidrahynokSort(a, n);
			break;
			
		case(3):
			mergesort(a, 0, n-1);
			break;
		
		default:
			printf("Error");
			break;
  	}
  	                 // output                        çàêîìåíò ïðè áîëüøèõ çíà÷åíèÿõ n
	
  	printf("\n");
  	for (i = 0; i<n; i++)
  	{
    	printf("%7d ", a[i]);
    }
    printf("\n");
    
  	printf("\nNumber of changes = %.0lf\n", ch);
  	printf("Number of equals = %0.lf", eq); 

 	getch();  
	return 0;
}


void obminsort(int a[], int n) 
{
	int i,r,k,temp;
	r=n-1;
	
	while(r>0)
	{
		k=0;
		for(i=0; i<=r; i++)
		{
			eq++;
			if(a[i]>a[i+1])
			{
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;	
				k=i;
				ch++;
			}
		}
		r=k;
	}
}


void pidrahynokSort(int a[], int n) 
{
	int k, i, j, b[n] ;
	k=a[0];
	
	for(i=0; i<n; ++i)
	{
		if(k<a[i])              // èùåì ìàêñ â ýëåìåíò â ìàññèâå à
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
		ch++;
	}
	
	for(i=0; i<n; i++)
	{
		a[i]=b[i];
	}
}


void mergesort(int a[],int left,int right)
{
    int m; 
    if(left<right)
    {
        m=(left+right)/2;
        mergesort(a,left,m);                       //ëåâàÿ ðåêóðñèÿ 
        mergesort(a,m+1,right);                                    // ïðàâàÿ ðåêóðñèÿ 
        merge(a,left,m,m+1,right);                                            //ñëèÿíèå äâóõ îòñîðòèðîâàííûõ ïîäìàññèâîâ
    }
}


void merge(int a[],int l1,int l2,int r1,int r2)
{
    int temp[r2];                        // ìàññèâ, èñïîëüçóåìûé äëÿ ñëèÿíèÿ
    int left,right,k;
    
    left=l1;                                                           // íà÷àëî ïåðâîãî ñïèñêà
    right=r1;                                                                         // íà÷àëî âòîðîãî ñïèñêà
    k=0;
    
    while((left<=l2) && (right<=r2))                             // äî òåõ ïîð, ïîêà ýëåìåíòû â îáîèõ ñïèñêàõ
    {
        if(a[left]<a[right])
        {
        	eq++;
        	temp[k++]=a[left++];
        	ch++;
		}
		
        else
        {
        	eq++;
        	temp[k++]=a[right++];
        	ch++;
		}    
    }
    
    while(left<=l2)                           //êîïèðóåì îñòàâøèåñÿ ýëåìåíòû ïåðâîãî ñïèñêà
    {
    	temp[k++]=a[left++];
    	ch++;
	} 
	
    while(right<=r2)                                                  // êîïèðóåì îñòàâøèåñÿ ýëåìåíòû âòîðîãî ñïèñêà
    {
    	temp[k++]=a[right++];
    	ch++;
	}
	
    for(left=l1,right=0;left<=r2;left++,right++)          // Ïåðåíåñèòå ýëåìåíòû èç temp  îáðàòíî â à
    {
    	ch++;
    	a[left]=temp[right];	
	}      
}
