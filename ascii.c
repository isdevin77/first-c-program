/* Demonstrates printing extended ASCII characters */

#include <stdio.h>

unsigned char mychar;   /* Must be unsigned for extended ASCII */

int main( void )
{
    /* Print extended ASCII characters 180 through 203 */

    for (mychar = 180; mychar <= 204; mychar++)
    {
        printf("ASCII code %d is character '%c'\n", mychar, mychar);
    }

    return 0;
}