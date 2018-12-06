#include <stdio.h>
#include <cs50.h>

int main(void)
{
    float c;
    do
    {
        c = get_float("Change owed: ");

    }
    while(c < 0 || c < 0.009);

    int x = 0;


        c = c + 0.0004;



    int y = (c * 10.0f) * 10;
    int m = 0;
    int n = 0;
    int p = 0;
    int r;



   for (int i = y; y >= 25; y = y - 25)
    {
        x = x + 1;
    }
    printf("Quarters: %i\n", x);


   for(int j = y; y >= 10; y = y - 10)
    {
        m = m + 1;
    }
    printf("Dimes: %i\n", m);



   for(int k = y; y >= 5; y = y - 5)
    {
        n = n + 1;
    }
    printf("Nickles: %i\n", n);


   for(int l = y; y >= 1; y = y - 1)
    {
        p = p + 1;
    }
    printf("Pennies: %i\n", p);

    r = x + m + n + p;

    printf("Total coins: %i\n", r);
}