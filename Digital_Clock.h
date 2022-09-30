
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define RESET		0
#define BRIGHT 		1

#define BLACK 		0
#define RED			1
#define GREEN		2
#define YELLOW		3
#define BLUE		4
#define MAGENTA		5
#define CYAN		6
#define	WHITE		7
#define DONT_CARE	8

extern int columns;

void textcolor(int,int,int);
int input_colour(char *);
int identify_digit(char);
void fix_digit(char, int, int);
int block_position(int );
void print_digit(int (*array)[6], int, int);
void print_colon(int, int);
