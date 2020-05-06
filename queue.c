#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int *array;
	int n;
	int head;
	int tail;
} queue;

queue * init_queue(int);
void free_queue(queue *);
int queue_empty(queue *);
int queue_full(queue *);
void enqueue(queue *, int);
int dequeue(queue *);

int main(){
	int i, N;
	printf("enter queue size: ");
	scanf("%d", &N);
	queue *q = init_queue(N);
	printf("\nfill the queue:\n\n");
	for(i=0; i<=N; i++) {
		printf("enqueue: %d\n", i);
		enqueue(q, i);
	}
	printf("\nclear the queue:\n\n");
	for(i=0; i<=N; i++) printf("%i\n", dequeue(q));
	free_queue(q);
	return 0;
}

queue * init_queue(int n){
	queue * result = (queue *)malloc(sizeof(queue));
	result->array = (int *)malloc(n*sizeof(int));
	result->head = 0;
	result->tail = 0;
	result->n = n;
	return result;
}
void free_queue(queue *q){
	free(q->array);
	free(q);
}
int queue_empty(queue *q){
	int res=0;
	if (q->head == q->tail) res=1;
	return res;
}
int queue_full(queue *q){
	int res=0;
	if ((q->head == q->tail+1) || ((q->head == 0) && (q->tail == q->n))) res=1;
	return res;
}
void enqueue(queue *q, int x){
	int res=queue_full(q);
	if (res) puts("ERROR: QUEUE OVERFLOW"); else{
		(q->array)[q->tail]=x;
		if (q->tail == q->n) (q->tail)=0; else q->tail++;
	}
}
int dequeue(queue *q){
	int x=0;
	int res=queue_empty(q);
	if (res) puts("ERROR: QUEUE UNDERFLOW"); else{
		x=(q->array)[q->head]; 
		if (q->head == q->n) q->head=0; else q->head++;
	}
	return x;
}
