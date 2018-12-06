#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    long long n;
    int h;
    do
    {
        n = get_long_long("Number: ");
        h = log10(n) + 1;
    }
    while (n < 0 || h > 16);
//h is the number of digits in n
    int ccnum[18];
//puts values of n into array
    int m = h;
    long long j = 10, k = 1, l;
    do
    {
        l = (n % j) - (n % k);
        if (l >= 10)
        {
            l = l / k;
        }
        ccnum[m] = l;
        j *= 10;
        k *= 10;
        m--;
    }
    while (m >= 0);
//just to be on the safe side
    j = 0;
    k = 0;
    ccnum[17] = 0;
//if h is less than 16 it will erase the garbage values
    if (h < 16)
    {
        ccnum[16] *= 0;
        if (h < 15)
        {
            ccnum[16] *= 0;
            ccnum[15] *= 0;
            ccnum[14] *= 0;

        }
    }

//MASTERCARD, AMEX, or VISA if card starts with certain 2 numbers
    string e;
    if (ccnum[1] == 5 && (ccnum[2] <= 5 && ccnum[2] != 0))
    {
        e = "MASTERCARD";
    }
    if (ccnum[1] == 3 && (ccnum[2] == 4 || ccnum[2] == 7))
    {
        e = "AMEX";
    }
    if (ccnum[1] == 4)
    {
        e = "VISA";
    }
//invalid if they start with numbers valid cards would not start with
    if (ccnum[1] <= 2 || ccnum[1] >= 6 || (ccnum[1] == 5 && (ccnum[2] > 5 || ccnum[2] < 1)))
    {
        e = "INVALID";
    }
    if (ccnum[1] == 3 && (ccnum[2] == 5 || ccnum[2] == 6 || ccnum[2] < 4 || ccnum[2] > 7))
    {
        e = "INVALID";
    }
    if (ccnum[1] <= 2 || ccnum[1] >= 6)
    {
        e = "INVALID";
    }


//multiply every other number by 2 starting from right to left
    int z = h - 1;
    while (z > 0)
    {
        ccnum[z] *= 2;
        z -= 2;
    }
//if values that were multiplied by 2 are bigger than 10 it breaks apart digits and adds them later
    int s = h - 1;
    int b = 0;
    while (s > 0)
    {
        if (ccnum[s] >= 10)
        {
            b = ccnum[s] % 10;
            ccnum[s] = (ccnum[s] - b) / 10;
        }
        ccnum[17] += b;
        b = 0;
        s -= 2;
    }

// sum of non multiplied card numbers
    int u = 1, v = 1;
    if (h == 16)
    {
        v = ccnum[2] + ccnum[4] + ccnum[6] + ccnum[8] + ccnum[10] + ccnum[12] + ccnum[14] + ccnum[16];
        u = ccnum[1] + ccnum[3] + ccnum[5] + ccnum[7] + ccnum[9] + ccnum[11] + ccnum[13] + ccnum[15] + ccnum[17];
    }
    if (h == 15)
    {
        v = ccnum[1] + ccnum[3] + ccnum[5] + ccnum[7] + ccnum[9] + ccnum[11] + ccnum[13] + ccnum[15];
        u = ccnum[2] + ccnum[4] + ccnum[6] + ccnum[8] + ccnum[10] + ccnum[12] + ccnum[14] + ccnum[17];
    }
    if (h == 13)
    {
        v = ccnum[1] + ccnum[3] + ccnum[5] + ccnum[7] + ccnum[9] + ccnum[11] + ccnum[13];
        u = ccnum[2] + ccnum[4] + ccnum[6] + ccnum[8] + ccnum[10] + ccnum[12] + ccnum[17];
    }
//sum of non multiplied and multiplied
    v = v + u;
//does the total end with a 0?
    v %= 10;
//if v ends in 0
    if (v < 1 && v >= 0)
    {
        printf("%s\n", e);
    }
    else
    {
        printf("INVALID\n");
    }
}


