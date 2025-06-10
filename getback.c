/* getback.c--Demonstrates using the gets() return value. */

# include <stdio.h>
#include <string.h>

/* Declare a character array to hold input, and a pointer. */

char input[257], *ptr;

int main( void ) 
{
    /* Display instructions */
    puts("Enter text a line at a time, then press Enter.");
    puts("Enter a blank line when done.");

    /* Loop as long as input is not a blank line. */

    while (1)
    {
        fgets(input, sizeof(input), stdin);

        // Remove newline character if present
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n')
            input[len - 1] = '\0';

        // Check for blank line (user pressed Enter)
        if (input[0] == '\0')
            break;

        printf("You entered %s\n", input);
    }

    puts("Thank you and good-bye");
}