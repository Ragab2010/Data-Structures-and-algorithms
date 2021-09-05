/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: ENG.HamaDa
 */


#include <stdio.h>

union x{
	char a ;
	short b;
};


int main(){
//	 short x = 0xFE40;
//	 char b =x;
//	printf("%x" ,b);
//    unsigned char a = 0xff;
//    char b = 0xff;
//    printf("A: %08x, B: %08x\n", a, b);
//	short  x=-12;
//	unsigned short y=8;
//	 short f = x+y;
//	char x= -5;
//	 long long y = 16;
//	if(y>x){
//		printf("true");
//	}else
//		printf("false");

//	float a =-1/0;
//	unsigned int *p =&a;
//	//*p=0x3f800000;
//	printf("%x" , *p);

	union x te;
	te.a=1;
	te.b=256;
	printf("%d %d" ,te.a , te.b );

	return 0;
}
