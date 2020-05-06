#include "2018_12_12_ads_tree_pure_c.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 8
#define R 60

int main(){
	int i=0;
	ntree * root = NULL;
	srand(time(NULL));
	int a[N] = {42,18,5,71,9,61,4,200}; 
	
	for (i=0; i<N; i++) {
		
		int key = rand()%R + 1;
		printf("%d\t", a[i]);
		root = build_tree(root, root, a[i]);
	}
	printf("\nPREORDER\n");
	preorder(root);
	
	printf("\nINORDER\n");
	inorder(root);
	
	printf("\nPOSTORDER\n");
	postorder(root);
	
	printf("\n%d nodes were deleted\n", free_tree(root));
	return 0;
}
