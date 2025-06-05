/* expenses.c - Demonstrates use of an array */

#include <stdio.h>

/* Declare an array to hold expenses, and a counter variable */

float expenses[13];
int count;
float year_expenses = 0;

int main( void )
{
    /* Input data from keyboard into array */

    for (count = 1; count < 13; count++)
    {
        printf("Enter the expenses for month %d: ", count);
        scanf("%f", &expenses[count]);
    }

    /* Print array contents */

    for (count = 1; count < 13; count++)
    {
        printf("Month %d: %.2f\n", count, expenses[count]);
        year_expenses += expenses[count];
    }
    printf("Total expenses for the year: %.2f\n", year_expenses);
    return 0;
}