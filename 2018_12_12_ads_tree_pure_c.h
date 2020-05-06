#include <stdio.h>
#include <stdlib.h>

typedef struct node_tree{
	int key;
	struct node_tree * left, * right;
} ntree;

typedef struct node_tree * ptr;

ntree * build_tree(ntree *, ntree *, int);

void inorder(ptr);
void preorder(ntree *);
void postorder(ntree *);

int free_tree(ntree *);

ntree * build_tree(ntree * root, ntree * node, int key){
	if (!node){
		
	node = (ntree *) malloc(sizeof(ntree));
	if (!node) {
		printf("\nERROR: Bad allocation!");
		exit(1);
	}

	node->left = node->right = NULL;
	node->key = key;
	
	if (!root) return node; // create root
	
	if (key < root->key) root->left = node;
	else root->right = node;
	return node;
	}
	if (key < node->key) build_tree(node, node->left, key);
	else build_tree(node, node->right, key);
	
	return root;
}

void inorder(ptr h){
	// ..
}

void postorder(ntree * h){
	// ..
}

void preorder(ntree * h){
	// ..
}

int free_tree(ntree * h){
	static int c = 0;
	
	if (h->left) free_tree(h->left);
	if (h->right) free_tree(h->right);

	if (h) {
		c++;
		free(h);
	}
	return c;
}
