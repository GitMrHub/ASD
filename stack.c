#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int *array;
	int n;
	int top;
} stack;

stack * init_stack(int);
void free_stack(stack *);
int stack_empty(stack *);
int stack_full(stack *);
void push(stack *, int);
int pop(stack *);

int main(){
	int i, N;
	printf("enter stack size: ");
	scanf("%d", &N);
	stack *st = init_stack(N);
	printf("\npush in stack:\n\n");
	for(i=0; i<=N; i++) {
		printf("push: %d\n",i);
		push(st, i);
	}
	printf("\npop from stack:\n\n");
	for(i=0; i<=N; i++) printf("%d\n", pop(st));
	free_stack(st);
	return 0;
}

stack * init_stack(int n){
	stack * result = (stack *)malloc(sizeof(stack));
	result->array = (int *)malloc(n*sizeof(int));
	result->n = n;
	result->top = -1;
	return result;
}

void free_stack(stack *s){
	free(s->array);
	free(s);
}

int stack_empty(stack *s){
	int res=0;
	if (s->top == -1) res=1;
	return res;
}
int stack_full(stack *s){
	int res=0;
	if (s->top == (s->n)-1) res=1;
	return res;
}

void push(stack *s, int x){
	int res=stack_full(s);
	if (res) puts("ERROR: STACK OVERFLOW"); else{
		(s->array)[++(s->top)] = x;
	}
}

int pop(stack *s){
	int x=0;
	int res=stack_empty(s);
	if (res) puts("ERROR: STACK UNDERFLOW"); else{
		x=(s->array)[(s->top)--];
	}
	return x;
}
