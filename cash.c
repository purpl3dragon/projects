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

    if(c <= 0.00999999978)
    {
        c = c + 0.0004;
    }

    int y = (c * 10.0f) * 10;



   for (int i = y; y >= 25; y = y - 25)
    {
        x = x + 1;
    }
   for(int j = y; y >= 10; y = y - 10)
    {
        x = x + 1;

    }
   for(int k = y; y >= 0.05; y = y - 5)
    {
        x = x + 1;

    }

   for(int l = y; y >= 0.01; y = y - 1)
    {
        x = x + 1;
    }

    printf("%i\n", x);
}