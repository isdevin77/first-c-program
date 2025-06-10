/* Demonstrates using scanf() to input numberic and text data, */

#include <stdio.h>

char lname[257], fname[257];
int count, id_num;

int main( void )
{
    /* Prompt the user. */

    puts("Enter your last name, first name, ID number serparated.");
    puts("by spaces, then press Enter.");

    /* Input the three data items. */

    count = scanf("%s%s%d", lname, fname, &id_num);

    /* Display the data. */

    printf("%d items entered: %s %s %d\n", count, lname, fname, id_num);

    return 0;
}