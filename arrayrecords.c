/* arrayrecords.c - Demonstrates using arrays of structures. */ 

#include <stdio.h>

/* Define a structure to hold entries. */

struct entry {
    char fname[20];
    char lname[20];
    char phone[13];
};

/* Declare an array of structures. */

struct entry list[4];

int i;

int main( void )
{
    /* Loop to input data for four people. */

    for (i = 0; i < 4; i++) 
    {
        printf("Enter first name: ");
        scanf("%s", list[i].fname);
        printf("Enter last name: ");
        scanf("%s", list[i].lname);
        printf("Enter phone number in 123-456-7890: ");
        scanf("%s", list[i].phone);
    }

    /* Print two blank lines. */

    printf("\n\n");

    /* Loop to display data. */

    for (i = 0; i < 4; i++)
    {
        printf("Name: %s %s\n", list[i].fname, list[i].lname);
        printf("Phone: %s\n", list[i].phone);
    }

    return 0;

}
