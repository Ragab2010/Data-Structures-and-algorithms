/*
 * main.c
 *
 *  Created on: ??�/??�/????
 *      Author: ENG.HamaDa
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10
#define NNODE 255
typedef struct node {
	int number ;
	int count ;
}Node;

int createHashTable(Node ** p , int numNode){
	*p = (Node *) malloc(sizeof(Node) *numNode);
	if(!p){
		return 0;
	}else{
		for(int i=0; i<numNode ; i++){
			p[0]->number =0;
			p[0]->count =0;
		}
		return 1;
	}
}

int insert(Node *p ,  int numNode,char *A , int numArray ){
	for(int i=0; i < numArray ; i++){
	p[A[i]%numNode].number=A[i];
	p[A[i]%numNode].count++;
	}
	return 1;
}

int checkDuplicate(Node *p ,int numNode){
	for(int i=0; i < numNode ; i++){
		if((p[i].count) >1){
			return ( p[i].number);

		}
	}
	return -1;
}

void HastableSumTwoNumber(Node *p , int numNode , int *A , int  numArray , int k){
	for(int i=0; i < numArray ; i++){
	p[A[i]%numNode].number=A[i];
	p[A[i]%numNode].count =1;
		if(p[k-A[i]].count == 1){
			printf("Element is : %d , %d \n" ,p[k-A[i]].number ,p[A[i]%numNode].number);
		}
	}
}
int hashTableSearch(Node *p , int data){
	if(p[data%NNODE].number == data){
		return 1;
	}else{
		return 0;
	}

}

void removeDuplicates(char *s){
	int current , last;
	Node *ph;
	createHashTable(&ph ,NNODE );
	insert(ph , NNODE ,s ,strlen(s) );
	current = last = 0;
	for (int var = 0; var < NNODE; ++var) {
		if(ph[var].count >0){
			printf("number=%c\t" , ph[var].number);
			printf("count=%d\n" , ph[var].count);
		}
	}
	for (; s[current] ;current++) {
		if(ph[s[current]%NNODE].count ==1){
			s[last++]=s[current];//ramyaAhmad
		}
	}
	s[last]='\0';

}

void removeChars(char *s , char *removeChrs){
	int srcind=0 , dstind=0;
	char hashtable[256];
	/*initialize hashtable with zeros*/
	for (int i = 0; i < 256; ++i) {
		hashtable[i]=0;
	}
	/*insert the  characters which will remove*/
	for (int i = 0; removeChrs[i]; ++i) {
		hashtable[(int)removeChrs[i]]=1;
	}
	/*now scan the input string to remove characters*/
//	for(;s[srcind];srcind++){
//		if(hashtable[(int)s[srcind]] == 0)
//			s[dstind++]=s[srcind];
//	}
	while(s[srcind]){
		if(!hashtable[(int)s[srcind]])
			s[dstind++]=s[srcind];
		srcind++;
	}
	s[dstind]='\0';
}

int main(){
	int a[N]={1,2,3,4,5,6,6,7,8,9};
	//Node *p;
	//createHashTable(&p , NNODE);
	//insert(p ,NNODE ,a , N );
	//printf("the number is : %d " , checkDuplicate(p , NNODE));
	//HastableSumTwoNumber(p , NNODE , a , N , 14);
	char s[] ="Ragab_Elsayed";
	char r[]="asg";
	//removeDuplicates(name );
	removeChars(s , r);
	printf("%s" , s);


	return 0;
}

