/*
 * main.c
 *
 *  Created on: May 28, 2019
 *      Author: ragab
 */
#include <stdio.h>


void heapify(int arr[], int n, int i)
{ int temp;
    int largest = i; // Initialize largest as root
    int l = 2*i + 1; // left = 2*i + 1
    int r = 2*i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        //swap(arr[i], arr[largest]);
    	temp = arr[i];
    	arr[i]= arr[largest];
    	arr[largest]=temp;

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n)
{	int temp;
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        //swap(arr[0], arr[i]);
    	temp = arr[0];
    	arr[0]= arr[i];
    	arr[i]=temp;

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}



void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        printf("%d " ,arr[i]);
    printf("\n");
}


#define MM 10
int main(){

	int a[MM]={2,9,11,0,22,3,4,7,10,100};
	heapSort(a , MM);
	printf("Sorted array is \n");
    printArray(a, MM);

printf("END");
	return 0;
}
