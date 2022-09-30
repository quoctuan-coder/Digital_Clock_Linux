#include "Digital_Clock.h"

int columns;

void textcolor(int attr, int fg, int bg)
{	
	char command[13];
	printf("\033[0m");

	if (attr == BRIGHT){
		if (fg == DONT_CARE){
			printf("\033[%dm", bg +40);
		}else{
			printf("\033[%dm", fg +30);
		}
	}
}

// Identifying the input colour
int input_colour(char *input){    			
	char *colours[]={"black","red","green","yellow","blue","magenta","cyan","white"};
	int count;					
	int array_size = sizeof(colours)/sizeof(colours[0]);

	for(count=0;count<array_size;count++){
 		if(strcmp(input,colours[count])==0){
 			return count;		
 		}
 	}
 	return 100;
}

// Identifying the input digit
int identify_digit(char input){    			
	char digits[]={'0','1','2','3','4','5','6','7','8','9'};
	int count;					
	int array_size = sizeof(digits)/sizeof(digits[0]);

	for(count=0;count<array_size;count++){
 		if(input==digits[count]){
 			return count;		
 		}
 	} 	
}

// Defining an array for each digit
void fix_digit(char input,int position,int colour){	
	int digit_array[5][6];
	int digit=identify_digit(input);
	
	if(digit==0){
		int digit_array[5][6]={			// 0
		{1,1,1,1,1,1},
		{1,1,0,0,1,1},
		{1,1,0,0,1,1},
		{1,1,0,0,1,1},
		{1,1,1,1,1,1}
	};
	}

	else if(digit==1){
		int digit_array[5][6]={			// 1
		{0,0,0,0,1,1},
		{0,0,0,0,1,1},
		{0,0,0,0,1,1},
		{0,0,0,0,1,1},
		{0,0,0,0,1,1}
	};
	}

	else if(digit==2){
		int digit_array[5][6]={			// 2
		{1,1,1,1,1,1},
		{0,0,0,0,1,1},
		{1,1,1,1,1,1},
		{1,1,0,0,0,0},
		{1,1,1,1,1,1}
	};
	}

	else if(digit==3){
		int digit_array[5][6]={			// 3
		{1,1,1,1,1,1},
		{0,0,0,0,1,1},
		{1,1,1,1,1,1},
		{0,0,0,0,1,1},
		{1,1,1,1,1,1}
	};
	}

	else if(digit==4){
		int digit_array[5][6]={			// 4
		{1,1,0,0,1,1},
		{1,1,0,0,1,1},
		{1,1,1,1,1,1},
		{0,0,0,0,1,1},
		{0,0,0,0,1,1}
	};
	}

	else if(digit==5){
		int digit_array[5][6]={			// 5
		{1,1,1,1,1,1},
		{1,1,0,0,0,0},
		{1,1,1,1,1,1},
		{0,0,0,0,1,1},
		{1,1,1,1,1,1}
	};
	}

	else if(digit==6){
		int digit_array[5][6]={			// 6
		{1,1,1,1,1,1},
		{1,1,0,0,0,0},
		{1,1,1,1,1,1},
		{1,1,0,0,1,1},
		{1,1,1,1,1,1}
	};
	}

	else if(digit==7){
		int digit_array[5][6]={			// 7
		{1,1,1,1,1,1},
		{0,0,0,0,1,1},
		{0,0,0,0,1,1},
		{0,0,0,0,1,1},
		{0,0,0,0,1,1}
	};
	}

	else if(digit==8){
		int digit_array[5][6]={			// 8
		{1,1,1,1,1,1},
		{1,1,0,0,1,1},
		{1,1,1,1,1,1},
		{1,1,0,0,1,1},
		{1,1,1,1,1,1}
	};
	}

	else if(digit==9){
		int digit_array[5][6]={			// 9
		{1,1,1,1,1,1},
		{1,1,0,0,1,1},
		{1,1,1,1,1,1},
		{0,0,0,0,1,1},
		{1,1,1,1,1,1}
	};
	}

	print_digit(digit_array,position,colour);
}


void print_digit(int (*array)[6],int position, int colour){

	int row_index,column_index;

	for(row_index=0;row_index<5;row_index++){
		for(column_index=0;column_index<6;column_index++){
			printf("\033[%d;%dH",row_index+2,column_index+block_position(position));
			int value = array[row_index][column_index];
			if(value==0){
				textcolor(RESET, WHITE, BLACK);
				printf(" ");
			}
			else if(value==1){
				textcolor(BRIGHT, DONT_CARE, colour);
				printf(" ");
			}
		}
		textcolor(RESET, WHITE, BLACK);	
	}		
}

		
int block_position(int digit_position){
	int spacing;
	
	// Getting size of the terminal 
	struct winsize w;
	ioctl(STDOUT_FILENO,TIOCGWINSZ,&w);
	columns = w.ws_col;

	if (digit_position==0)
		spacing=2;
	else if(digit_position==1)
		spacing=9;
	else if(digit_position==3)
		spacing=21;
	else if(digit_position==4)
		spacing=28;
	else if(digit_position==6)
		spacing=40;
	else if(digit_position==7)
		spacing=47;

	return spacing + (columns/2 - 22);
}

// Printing the colon
void print_colon(int position, int colour){		
	
	int row_index,column_index;

	int array[5][6]={				// Defining an array for a colon
		{0,0,0,0,0,0},
		{0,0,1,1,0,0},
		{0,0,0,0,0,0},
		{0,0,1,1,0,0},
		{0,0,0,0,0,0}
	};

	for(row_index=0;row_index<=5;row_index++){		// Printing the colon
		for(column_index=0;column_index<=6;column_index++){
			printf("\033[%d;%dH",row_index+2,column_index+position + (columns / 2 - 22));
			if(array[row_index][column_index]==0){
				textcolor(RESET, WHITE, BLACK);
				printf(" ");
			}
			else if(array[row_index][column_index]==1){
				textcolor(BRIGHT, DONT_CARE, colour);
				printf(" ");
			}

		}
	textcolor(RESET, WHITE, BLACK);
	putchar('\n');
	}		
}

