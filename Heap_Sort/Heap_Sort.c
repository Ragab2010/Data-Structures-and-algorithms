


/*
   -A heap is a tree with some special properties. The basic requirement of a heap is that the value of
	a node must be ≥ (or ≤) than the values of its children. This is called heap property.

	Types of Heaps: Min heap ,Max heap
		Parent of a Node = ()i-1/2   , Parent has two children , left and right
		Children of a Node  --left =2*i + 1  , right = 2*i + 2

 */
#include <stdio.h>
#include <stdlib.h>
/*create the heap */

typedef struct {
	int* array ;
	int count ;
	int capacity;
	int heap_type;
}HEAP;


int parent(HEAP *p , int i);
HEAP * createHeap(int cap , int heap_type);
int leftChild(HEAP *p , int i);
int rightChild(HEAP *p , int i);
int getMax(HEAP *p);
void percolateDown(HEAP *p , int i );
int deleteMax(HEAP * p );
int  insert(HEAP *p , int data );
int  resizeHeap(HEAP *p);
int destroyHeap(HEAP *p );
int buildHeap(HEAP *p ,int *a  , int n);
int heapSort(int *a , int n);

#define MM 10
int main(){

	int a[MM]={2,9,11,0,22,3,4,7,10,100};
	heapSort(a , MM);

printf("\n");
printf("END");
	return 0;
}



/*************IMPLEMENTATION***********/

int parent(HEAP *p , int i){
		if(i <=0 || i >= p->count ){
			return -1;
		}else{
			return (i-1)/2;
		}
}



HEAP * createHeap(int cap , int heap_type){
	HEAP * pt = (HEAP* ) malloc(sizeof(HEAP ));
	if(!pt){
		printf("Memory error");
		return NULL;
	}
	pt->capacity = cap;
	pt->heap_type = heap_type;
	pt->count=0;
	pt->array = (int *) malloc(sizeof(int)* cap);
	if(!pt->array){
		printf("Memory error");
		return NULL;
	}
	return pt;

}

int leftChild(HEAP *p , int i){
	int left =2*i + 1;
	if(left >= p->count){
		return -1;
	}
	return left;
}
int rightChild(HEAP *p , int i){
	int right =2*i + 2;
	if(right >= p->count){
		return -1;
	}
	return right;
}

int getMax(HEAP *p){
	if(p->count ==0)
		return -1;
	return p->array[0];
}

void percolateDown(HEAP *p , int i ){
	int  l , r , max , temp;
	 l = leftChild(p , i );
	 r = rightChild(p , i);
	 if((l != -1)&&(p->array[l]>p->array[i])){
		 max = l;
	 }else{
		 max = i;
	 }
	 if((r != -1)&&(p->array[r] > p->array[max])){
		 max = r;
	 }
	 if(max != i){
		 temp = p->array[i];
		 p->array[i]=p->array[max];
		 p->array[max]=temp;

	 }else{
		 return ;
	 }

	 percolateDown( p , max);

}

int deleteMax(HEAP * p ){
	int data;
	if(!p){
		return -1;
	}
	data= p->array[0];
	 p->array[0]= p->array[p->count-1];
	 percolateDown( p , 0);
	 return data;
}

int  insert(HEAP *p , int data ){
	int i;
	if(p->count == p->capacity){
		resizeHeap(p);
	}
	p->count++;
	i=p->count-1;
	//p->array[i]=data;
	while((i>=0) && (data >p->array[(i-1)/2])){
		p->array[i]=p->array[(i-1)/2];
		i=(i-1)/2;
	}
	p->array[i]=data;
return 1;
}
int  resizeHeap(HEAP *p){
	int * old_arry = p->array;
	p->array = (int *)malloc(sizeof(int)*p->capacity *2);
	if(!p->array){
		printf("Memory Error");
		return 0;
	}
	for(int i =0; i<p->capacity ; i++){
		p->array[i]=old_arry[i];
	}
	p->capacity *=2;
	free(old_arry);

	return 1;
}

int destroyHeap(HEAP *p ){
	if(!p)
		return 1;
	else{
		free(p->array);
		free(p);
		return 1;
	}
}

int buildHeap(HEAP *p ,int *a  , int n){
	if(!p)
		return -1;

	while( n > p->capacity){
		resizeHeap(p);
	}
	for (int i = 0; i < n; ++i) {
		p->array[i]= a[i];
	}
	p->count =n;
	for (int i = (n-1)/2; i >=0; i--) {
		percolateDown(p , i);
	}
	return 1;

}

int heapSort(int *a , int n){
	int old_size , i , temp;

	HEAP * p = createHeap(n , 1);

	buildHeap(p , a , n);
	old_size =p->count;

	for ( i = n-1; i > 0; i--) {
		temp =p->array[0];
		p->array[0] =p->array[i];
		p->array[i] =temp;
		p->count--;
		percolateDown(p , 0);
	}
	p->count =old_size;
	for (int var = 0; var < 10; ++var) {
		printf("%d\t" , p->array[var]);
	}
	destroyHeap(p );
	return 1;

}










