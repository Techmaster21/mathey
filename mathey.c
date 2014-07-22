#include <stdio.h>
#include <string.h>
#include "mathey.h"

int main() {
	char mode[80]; //For storing the string the user enters as desired mode of operation.
	char f; //For cleaning stdin before passing to an outside function that requires input(Fixes various bugs)
	puts("Enter desired mode of operation:");
	while (1) {
		printf("math> ");
		scanf("%s", &mode);
		if (strcmp(mode,"calc") == 0)
			while ((f=getchar() != '\n' && f != EOF); //Making stdin squeeky clean
			calc();
		else if (strcmp(mode,"matrix") == 0) {
			while ((f=getchar() != '\n' && f != EOF); //Making stdin squeeky clean
			printf("math>matrix>\n");
			matrix();
		}
		else if (strcmp(mode,"help") == 0 || strcmp(mode,"?") == 0)
			help();
		else if (strcmp(mode,"quit") == 0 || strcmp(mode,"q") == 0 || strcmp(mode,"exit") == 0)
			break;
		else
			puts("I do not understand that command. Please try again, or enter quit to quit."); 
	}
	return 0;
}
