#include <stdio.h>
#include <string.h>
#include "math.h"

void calc() {
/* What I want this to do: read from input, place arguments seperated by spaces into seperate strings like argv[] does. 
Assume every other argument is an operator. Calculate accordingly. 
Dissadvantages: 5+4 would not be understood.*/
	char f;
	while ((f=getchar()) != '\n' && f != EOF);
	char equ[80];
	char *p;
	int i = 0;
	int a[10];
	scanf("%[^\n]", equ);
	printf("%i", i);
	while (p = strchr(equ,'+')) {
		i = (int) p - (int) &equ;
		sscanf(equ, "%i", a[0]);
		for();		
	}
	printf("%i", a[0]);
}
