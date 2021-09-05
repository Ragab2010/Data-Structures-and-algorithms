/*
 * bubleSort.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: ENG.HamaDa
 */


#include <stdio.h>


void BubleSort(int *pa , int n){
	int i, j , flage=1;
	int temp=0;
	for(i=n-1 ; (i>=0 )&&flage ; i--){
		flage=0;
		for(j=0; j<i ; j++){
			if(pa[j] > pa[j+1]){
				/***swap***/
				temp=pa[j];
				pa[j]=pa[j+1];
				pa[j+1]=temp;
				flage =1;
			}
		}
	}

}

void SelectionSort(int *pa, int n){
	 int i , j ,min ;
	int temp=0;
	for(i =0 ; i<n ; i++){
		min =i;
		for(j=i+1 ; j<n ; j++){
			if(pa[j] < pa[min]){
				min =j;
			}
		}
		/***swap***/
		temp=pa[min];
		pa[min]=pa[i];
		pa[i]=temp;

	}

}

void InselectionSort(int *pa , int n){
	int i , j , temp ;
	for(i=1 ; i<n ; i++){
		for(j=i ; j>0 ; j--){
			if(pa[j] < pa[j-1]){
				/***swap***/
				temp=pa[j-1];
				pa[j-1]=pa[j];
				pa[j]=temp;
			}
		}
	}

}

void fun_insetSort(int *a ,int size){
	int i,j,temp;
	for(i=1; i< size ;i++){
		for(j = i ; (a[j]<=a[j-1]) && j>0; j--){
			temp = a[j-1];
		    a[j-1] = a[j];
		    a[j] = temp;
		}
	}

}

//this algorithm improve insertion sort
void ShellSort(int *pa , int n){
	int gap , i , temp;
	for(gap =n/2; gap >0 ; gap /=2){
		for(i=0 ;(gap + i)<n ;i++){
			while((pa[i]> pa[gap+i]) && i>=0){
				/***swap***/
				temp=pa[gap+i];
				pa[gap+i]=pa[i];
				pa[i]=temp;
				i-=gap;
			}
		}
	}
}
void shellsort2( int *a , int n){
	int gap , temp , i , j;
	for(gap = n/2 ; gap >0;gap/=2){
		for(i=0 ; (gap+i)<n ; i++){
			for(j=i;(j>=0)&&(a[j]> a[gap+j]);j-=gap){
				temp=a[gap+j];
				a[gap+j]=a[j];
				a[j]=temp;
			}

		}
	}
}


void CountSort(int a[] , int n , int B[] , int k){
	int c[k];
	for (int var = 0; var < k; ++var) {
		c[var] =0;
	}
	for (int var = 0; var < k; ++var) {
		c[a[var]] = c[a[var]] +1;
	}
	for (int var = 0; var < n; ++var) {
		printf("  %d\t" , a[var]);
	}
	printf("\n");
	for (int var = 0; var <n; ++var) {
		printf("c[%d]\t" , var);
	}
	printf("\n");
	for (int var = 0; var <n; ++var) {
		printf("  %d\t", c[var]);
	}
	printf("\n");
	for (int var = 0; var <n; ++var) {
		printf("--------");
	}
	printf("\n");
	for (int var = 1; var <n; ++var) {
		c[var] = c[var] +c[var-1];
	}
	printf("\n");
	for (int var = 0; var <n; ++var) {
		printf("  %d\t", c[var]);
	}
	printf("\n");
	for (int var =n-1; var>=0; --var) {
		B[c[a[var]]-1] =a[var];
		c[a[var]] = c[a[var]] -1;
	}
	for (int var = 0; var <=9; ++var) {
		printf("------");
	}
	printf("\n");
	for (int var = 0; var <n; ++var) {
		printf("  %d\t", B[var]);
	}


}
int binarySearchFristOccurrence(int *a , int low , int high , int data){
	int mid ;
	while(low <= high){
		mid = low +(high - low)/2;
		if((low == high && a[mid]==data) || (a[mid] == data && a[mid - 1] <data))
			return mid;
		else if (a[mid]>= data)
			return binarySearchFristOccurrence(a , low , mid-1 , data );
		else
			return binarySearchFristOccurrence(a , mid+1 , high , data);
	}

	return -1;
}

/****************merge sort*****************/
void merge(int *l , int *r , int *a, int nl , int nr ){
	int i , j , k;// make counter for every arr (left - right -orginal a)
	i =0; j =0;k = 0; //make it count from zero
	while(i<nl && j<nr){
		/*
		 * while  i and j (left and right arr ) has element
		 * */
		if(l[i] < r[j]){
			a[k++] = l[i++];

		}else{
			a[k++] = r[j++];

		}
	}
	while(i<nl){/*
	while left arr still has element only and right is finished */
		a[k++] = l[i++];

	}
	while(j<nr){/*
	while right arr still has element only and left  is finished */
		a[k++] = r[j++];

	}
}

void mergesort(int *a , int n){
	int mid,i,nl,nr;
	if( n <2){//this is the base condition for stop and return recursive
		return;
	}
	mid = n/2;//calc the midel of a
	nl=mid; //size of left arr
	nr=n-mid;//size of right arr
	int left[nl];//create arr for left arr by size of it nl
	int right[nr];//create arr for right arr by size of it nr
	for(i=0 ; i<mid ;i++){//copy elemnt from 0 to mid to left arr
		left[i] = a[i];
	}
	for(i=mid; i<n; i++){//copy elemnt from mid to n to right arr
		right[i-mid] = a[i];
	}
	mergesort(left , nl);// recursive call for sort left arr
	mergesort(right , nr);// recursive call for sort right arr
	merge(left , right , a ,nl , nr);// cal merge fun to merge the left and right arr in the orginal arr a
}


/***************quick sort*******************/

int partition(int *a , int start , int end){
	int i, temp; // i for loop and temp for swap
	int pivot = a[end];//make pivot the last element in arr
	int partitionIndex = start;/**
	*for place all elment that's is small than pivot in the frist arr
	*pefor the pivot
	*/
	for(i=start ; i < end;i++){//count from 0 to end-1 before pivot
		if(a[i] <= pivot){
			/*for swap all the small than pivot in the frist arr*/
			temp = a[i];
			a[i] = a[partitionIndex];
			a[partitionIndex]=temp;
			partitionIndex++;// increment the position that will place in head of arr
		}
	}
	/*then swap the pivot with the frist large element than pivot*/
	temp = a[end];
	a[end] = a[partitionIndex];
	a[partitionIndex]=temp;
	return partitionIndex;//return the position of pivot for send right arr and left arr

}
void quicksort(int *a , int start, int end){

	if(start < end){//conditon for return if the arr is 1 element
	int partionIndex = partition(a, start , end);
	quicksort(a ,start ,  partionIndex -1);//recursive the left arr to sort and make partition
	quicksort(a , partionIndex +1 ,end );//recursive the right arr to sort and make partition
	}

}


int main(){

	int a[8]={3,2,1,0,9,4,3,1};
	//int c[8]={3,2,1,0,9,4,3,1};
	int B[10]={0};

//	ShellSort(a , 8);
//	for (int var = 0; var <8; ++var) {
//		printf("  %d\t", a[var]);
//	}

//	CountSort(a , 8 , B , 10);
//	printf("\n");
//	for (int var = 0; var <8; ++var) {
//		printf("  %d\t", B[var]);
//	}
	int b[9]={1,2,3,4,5,5,5,6,7};

	printf("index= %d " , binarySearchFristOccurrence(b , 0 , 8 , 5));

//	int a[10]={9,2,4,6,8,7,1,10,3,58};//{10,8,7,8,4,15};
//	ShellSort(a , 10);
//	for ( int var = 0;  var <10 ; var++) {
//		printf("%d\n" ,a[var]);
//	}


	return 0;
}

