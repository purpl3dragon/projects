#include <cs50.h>
#include <stdio.h>

int main(void)
{
int n;
    do
    {
        n = get_int("Number: ");
    }
    while (n < 0 || n > 23);

if( n > 0)
{
int o = n - ( n - 1);
int p = n;

do
{
    for (int j = n - 1; j > 0; j--)
    {
    printf(" ");
    }
    for( int k = o; k > 0; k--)
    {
            printf("#");
    }
    if(n > 0)
    {
    printf("  ");
    }
    for(int l = o; l > 0; l--)
    {
        printf("#");
    }

    if(n > 0)
    {
    printf("\n");
    }
    o = o + 1;
    n = n - 1;
}
while(o <= p);
}

}