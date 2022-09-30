#include "Digital_Clock.h"

int columns;

int main(int argc, char **argv)
{
	
	int position;
	int i;
	int colour_1;

	colour_1 = input_colour("red");	

	// Hiding the cursor
	printf("\033[?25l");
	// Clear console
	printf("\033[2J");		
 	
	while(1)
	{
		char time_value[20];
  		char date[20];
  		time_t current_time;  		// time_t: a data type used to store system time values
  		current_time = time(NULL);  // time elapsed (in seconds) since Epoch
  
  		struct tm* brokentime = localtime(&current_time);   // Converts to broken down time 
  
  		strftime(time_value,20,"%X", brokentime);	// Current time
  		strftime(date,20,"%Y-%m-%d", brokentime);	// Date
	
  	
  	for(position=0;position<2;position++)	// Print the first two digits
  		fix_digit(time_value[position],position,colour_1);

  	print_colon(15,colour_1);		// Print colon

  	for(position=3;position<5;position++)	// Print the second two digits
  		fix_digit(time_value[position],position,colour_1);

  	print_colon(34,colour_1);

  	for(position=6;position<8;position++)		// Print the last two digits
  		fix_digit(time_value[position],position,colour_1);

  	printf("\033[8;%dH",columns / 2);
	textcolor(BRIGHT, colour_1, DONT_CARE);
  	
  	for(i=0;i<12;i++){
  		printf("%c",date[i]);
  	}
  	
  	putchar('\n');
  	textcolor(RESET, YELLOW, BLACK);
  	sleep(1);
  	}
	
	return 0;
}