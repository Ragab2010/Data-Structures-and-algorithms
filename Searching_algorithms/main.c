/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: ENG.HamaDa
 */
#include <stdio.h>


int binarySearch(int *a , int n , int data){
	int low , high , middle;
	low = 0;high = n-1;
	while(low <= high ){
		middle = low + (high - low)/2;
		if(data > a[middle]){
			low = middle+1;
		}else if (data < a[middle]){
			high = middle-1;
		}else if(data == a[middle]){
			return middle;
		}
	}
	return  -1;
}

int binarySearchRecursive(int *a , int n , int data , int low , int high ){
	int  middle = low + (high - low)/2;
	if (low > high ){
		return -1;
	}else{
		if(data == a[middle])
			return middle ;
		if(data > a[middle]){
			binarySearchRecursive(a , n ,data , middle+1 , high );
		}else{
			binarySearchRecursive(a , n ,data , low ,  middle-1);
		}
	}


}

/***checkduplicate ***/
int abs(int data){
	if(data<0){
		data *= -1;
	}
	return  data;
}

void CheckDuplicate(int *a , int n){
	for(int i=0 ; i< n ; i++){
		if(a[abs(a[i])] < 0){
			printf("Duplicate exist:%d ",a[i]);
			return;
		}else{
			a[a[i]] = -a[a[i]];
		}

	}
	printf("No duplicates in given array");
}


/***Repitions Numbers***/
int MaxRepitionsBrusteForce(int *a , int n ){
	int counter=0 , max=0;
	for(int i=0; i<n ; i++){
		counter=0;
		for(int j=0; j < n ; j++){
			if(a[i] == a[j]){
				counter++;
			}
		}
		if(counter>max){
			max=counter;
		}
	}
	return max;
}
int FindMissingNumber(int *a , int n){
	int x=0;
	for (int i = 0; i < n; ++i) {
		x ^=a[i];

	}
	for (int i = 1; i <= 11; ++i) {
		x ^=i;
	}

	return x;
}


int FindRepeatedNumber(int *a , int n ,int minNumber, int maxNumber){
	int sum= 0;
	for(int i=0 ; i<n ; i++){
		sum ^= a[i];
	}
	for(int i=minNumber ; i<=maxNumber ; i++){
		sum ^= i;
	}

	return sum;
}


void FindRepeatedElement(int *a , int size){
	int i , k;
	for( i=0; i<size ; i++){
		for( k=0; k<size ; k++){
			if(a[i] == a[k]){
				printf("%d  " , a[i]);
			}

		}
	}

}

/*****search about two number equal to k  (array is sorted)*****/
void SearchTwo(int *a , int n , int k){
	int loIndex =0, hiIndex=n-1 , sum=0;
	//sort(a , n);
	while(loIndex < hiIndex){
		sum = a[loIndex]+a[hiIndex];
		if(sum == k ){
			printf("Element found: %d , %d\n" , a[loIndex] ,a[hiIndex]);
			return ;
		}
		else if (sum <k){
			loIndex++;

		}else
			hiIndex--;
	}
	return ;
}

struct node{
	int member;
	int count;
};
int find(int *a , int  n , struct node *pn ){
	int number_of_occ=0 ;
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			// to know numbers of occ
		}
	}
	*pn =(struct node *)malloc(sizeof(struct node ) * number_of_occ);

	return number_of_occ;
}
int find_occ(int *a , int n){


	return 0;
}
#define N 10
int main(){
	int a[N]={1,2,3,4,5,6,6,7,8,9};
	//int a[N]={1,4,3,4,2,7,6,4,1,1};
//	int i = binarySearchRecursive(a , N , 7,0 , 9);
//	printf("the index is= %d \n ", a[i]);
	//printf("%d" , FindRepeatedNumber(a , N , 1 ,9));
	SearchTwo(a , N , 14);
	struct node *arr_occ;
	int arr_size =find(a , 10 , &arr_occ);
	for (int i = 0; i < arr_size; ++i) {
		printf("number=%d\n " ,arr_occ[i].member);
		printf("count =%d\n " ,arr_occ[i].count);
	}
	return 0;
}

