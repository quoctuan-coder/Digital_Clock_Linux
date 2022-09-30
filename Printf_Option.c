#include "Digital_Clock.h"
#include <sys/ioctl.h>

int main()
{
    // printf("\033[?25l");	// Hiding the cursor
	// printf("\033[2J");		// Clear console

    // printf("\033[0m");

    // printf("\033[%dm", 31); // Set fg withred color
    // printf("\033[%dm", 42); // Set bg withred color
    // printf("QT\n"); 


    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    printf ("lines %d\n", w.ws_row);
    printf ("columns %d\n", w.ws_col);
    

    return 0;
}
