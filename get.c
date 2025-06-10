/* Demonstrates eusing the gets() library function */

#include <stdio.h>

/* Allocates a character array to hold input */

char input[257];

int main( void )
{
    puts("Enter some text, then press Enter:");
    fgets(input, sizeof(input), stdin);
    printf("You entered: %s\n", input);

    return 0;
}