//union2.c--Example of a typical use of a union2

#include <stdio.h>

#define CHARACTER 'C'
#define INTEGER 'I'
#define FLOAT 'F'

struct generic_tag{
    char type;
    union shared_tag{
        char c;
        int i;
        float f;
    } shared;
};

void print_function( struct generic_tag generic );

int main( void )
{
    struct generic_tag var;

    var.type = CHARACTER;
    var.shared.c = '$';
    print_function( var );

    var.type = FLOAT;
    var.shared.f = (float) 123.456;
    print_function( var );
    
    var.type = 'x';
    var.shared.f = 111;
    print_function( var );
    return 0;
}
void print_function( struct generic_tag generic )
{
    printf("\n\nThe generic value is...");
    switch( generic.type )
    {
        case CHARACTER:
            printf("Character: %c\n", generic.shared.c);
            break;
        case INTEGER:
            printf("Integer: %d\n", generic.shared.i);
            break;
        case FLOAT:
            printf("Float: %f\n", generic.shared.f);
            break;
        default:
            printf("Unknown type: %c\n", generic.type);
    }
}