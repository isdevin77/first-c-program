/* memalloc.c--Demonstrates the use of malloc() to allocate storage */
/* space for string data*/

#include <stdio.h>
#include <stdlib.h>

int main( void )
{
char *ptr, *p;
int count;

    /* Allocate a block of 27 bytes. Test for success. */
    /* The exit() library function terminates the program. */

    ptr = malloc( 27 * sizeof( char ) );

    if (ptr == NULL)
    {
        puts("Memory allocation error.");
        return 1;
    }

    /* Fill the string with values 65 through 90. */
    /* Which are the ASCII codes for A-Z */

    /*p is a pointer used to step through the string. */
    /* You want ptr to remain pointed at the start */
    /* of the string. */

    p = ptr;

    for (count = 65; count <= 90; count++)
        *p++ = (char)count;

    /* Add the terminating null character. */

    *p = '\0';

    /* Display the string on the screen. */

    puts(ptr);

    free(ptr);

    return 0; 
}