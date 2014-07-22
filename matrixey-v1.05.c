/* Program to row reduce a matrix
Version info:
1.00: Not actually the first version but the first time you finally decided to start versioning. Newer than anything without.
Changes: Improved readability, Seperated processes into functions rather than one long main(), 
removed unneccesary r+1(i.e. x[r+1][c+1]), workaround for restart issue
1.01: Restart issue fixed. Stray input still exists in stdin, and may want to figure out how to discard(Or convert to 
fgets and sscanf), but until then, it works properly.
1.02: Added basic error checking, improved input
1.03: Fixed -0 issue by changing y=0 to y=i in rowreduce()(So that it wasn't unnecessarily dividing 0 by d)
1.04: Rearranged code into a more logical order utilizing function declarations.

TODO:
Perhaps need to figure out how to remove excess input in stdin(Safely, cleanly, properly, and without performance 
degrading effects)
Improve/Refine error reporting
Add error reporting and checks to allow (main) function to be easily called by other programs and to be able to interpret error given
Further improve method of input(GUI?)
Improve output(ASCII(Or Unicode) matrix bracket)

To test: Does fgets discard extra characters in the buffer, or just leave them behind like scanf?
*/

#include <stdio.h>
//some global variables for rows, columns, and whether to run the program again or not
int r, c;
char restart;
//prototyping and function declarations
int startagain();
int getnums(double x[r][c+1]);
void rowreduce(double x[r][c+1]);
void eschform(double x[r][c+1]);
void printout(double x[r][c+1]);

int matrix() {
	do 
	{
	printf("Rows: ");
	if (scanf("%i", &r) != 1)
	{
		fputs("Invalid input\n", stderr);
		if (startagain())
			break;
		else
			continue;
	}
	printf("Columns: ");
	if (scanf("%i", &c) != 1)
	{
		fputs("Invalid input\n", stderr);
		if (startagain())
			break;
		else
			continue;
	}
	double x[r][c+1];
		
	if (getnums(x))
	{
		fputs("Invalid input\n", stderr);
		if (startagain())
			break;
		else
			continue;
	}
	rowreduce(x);
	eschform(x);
	printout(x);
	
	if (startagain())
		break;
	} while (restart == 'y');
	return 0;
}

//Takes input for numbers in matrix
int getnums(double x[r][c+1]) {
	double m, d = 1;
	int y, z;
	puts("Print matrix in standard form using tabs to seperate values\ne.g. for a 2x3 matrix, input:\n"
	"2	5	15\n"
	"1	2	7\n"
	"-------------------\n"
	"Input matrix:");
	for(y = 0; y < r; y++) 
	{
		for(z = 0; z < c; z++) 
		{
			switch (scanf("%lf/%lf\t", &m, &d)) 
			{
			case 2:
			case 1:
				x[y][z] = m/d;				
				break;
			default:
				return 1;
			}
		}
	}
	return 0;
}

//Row reduce the matrix
void rowreduce(double x[r][c+1]) {
	int n, y, i, z;
	double d;
	for(i = 0; i < r; i++) 
	{
		d = x[i][i];
		for(y = i; y < c; y++)
			x[i][y] /= d;
		for(n = i + 1; n < r; n++) 
		{
			d = x[n][i];
			for(z = 0; z < c; z++)
				x[n][z] += ((-d) * x[i][z]);
		}
	}
}

//Transform row reduced form into reduced row eschelon form
void eschform(double x[r][c+1]) {
	int i, n, j = r-1;
	for(i = c - 2; i >= 1; i--, j--) 
	{
		for(n = i - 1; n >= 0; n--) 
		{
			x[n][i] *= x[j][c-1];
			x[n][c-1] -= x[n][i];
			x[n][i] = 0;
		}
	}
}

void printout(double x[r][c+1]) {
	int y,z;
	puts("Resulting Matrix:");
/*	printf("⌈");
	for(y = 0; y < c - 1; y++)
		printf("\t");
	puts(" ⌉");
*/
	for(y = 0; y < r; y++) 
	{
//		printf("|");
		for(z = 0; z < c; z++)
			if (z != c-1)
				printf("%g\t", x[y][z]);
			else
				printf("%g\n", x[y][z]);
//		puts("|");
	}
/*	printf("⌊");
	for(y = 0; y < c - 1; y++)
		printf("\t");
	puts(" ⌋");
*/
}

int startagain() {
	char f;
	while((f = getchar()) != '\n' && f != EOF); /*This flushes the buffer to remove the 
						      invalid input */ 
	puts("Do you want to start again?(y/n)");
	scanf(" %c%*[^\n]", &restart);
	/*Space before % is so it ignores whitespace chars because that's not typical for %c unlike other format types
	%*[^\n] is supposed to catch the extra input and discard it(Though in other situations I have had it not work,
	it does in this one*/
	if (restart == 'y')
		return 0;
	else
		return 1;
}
