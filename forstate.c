/* Demonstrates a simple for statement */

#include <stdio.h>
#define MAXCOUNT 20
int count;

int main( void )
{
    /*Print the nunmber 1 through 20*/

    for (count = 1; count <= MAXCOUNT; count++)
        printf("%d\n", count);

    return 0;
}
