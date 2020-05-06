#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


void mergesort(int a[],int left,int right);
void merge(int a[],int l1,int l2,int r1,int r2);
 
int main()
{
    int n,i;
    printf("Enter n: ");
    scanf("%d",&n);                          // çŕäŕĺě đŕçěĺđ ěŕńńčâŕ
	int a[n];
	srand(time(NULL));
	for (i=0; i<n; i++)
	{
		a[i]=rand()%100;                        // ńîçäŕĺě đŕíäîěíűé íŕáîđ ýëĺěĺíňî â ěŕńńčâĺ
	}
	for (i=0; i<n; i++)
	{
		printf("%3d", a[i]);
	}
	printf("\n\n");
    mergesort(a,0,n-1);
    for(i=0;i<n;i++)
    {
    	printf("%3d ",a[i]);                           // âűâîäčě ěŕńńčâ
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
        mergesort(a,left,m);                       //ëĺâŕ˙ đĺęóđńč˙ 
        mergesort(a,m+1,right);                                    // ďđŕâŕ˙ đĺęóđńč˙ 
        merge(a,left,m,m+1,right);                                            //ńëč˙íčĺ äâóő îňńîđňčđîâŕííűő ďîäěŕńńčâîâ
    }
}


void merge(int a[],int l1,int l2,int r1,int r2)
{
    int temp[r2];                        // ěŕńńčâ, čńďîëüçóĺěűé äë˙ ńëč˙íč˙
    int left,right,k;
    left=l1;                                                           // íŕ÷ŕëî ďĺđâîăî ńďčńęŕ
    right=r1;                                                                         // íŕ÷ŕëî âňîđîăî ńďčńęŕ
    k=0;
    while((left<=l2) && (right<=r2))                             // äî ňĺő ďîđ, ďîęŕ ýëĺěĺíňű â îáîčő ńďčńęŕő
    {
        if(a[left]<a[right])
            temp[k++]=a[left++];
        else
            temp[k++]=a[right++];
    }
    while(left<=l2)                           //ęîďčđóĺě îńňŕâřčĺń˙ ýëĺěĺíňű ďĺđâîăî ńďčńęŕ
    {
    	temp[k++]=a[left++];
	} 
    while(right<=r2)                                                  // ęîďčđóĺě îńňŕâřčĺń˙ ýëĺěĺíňű âňîđîăî ńďčńęŕ
    {
    	temp[k++]=a[right++];
	}
    for(left=l1,right=0;left<=r2;left++,right++)          // Ďĺđĺíĺńčňĺ ýëĺěĺíňű čç temp  îáđŕňíî â ŕ
    {
    	a[left]=temp[right];	
	}      
}
