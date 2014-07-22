#include <stdio.h>
#include <string.h>
#include "mathey.h"

void calc() {
/* This don't work.*/
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
