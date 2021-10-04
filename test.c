#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int isPrime(int n)
{
    if (n <= 1)
        return 0;
    // checking for divisors of n in the range 2 to sqrt(n), if divisor found n is not a prime.
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}
int main()
{
    FILE *p, *fprime;
    p = fopen("input.txt", "r");
    fprime = fopen("output.txt", "w");
    if (p == NULL || fprime == NULL)
    {
        printf("Unable to open file\n");
        exit(1);
    }
    int x;
    while (fscanf(p, "%d", &x) != -1)
    {
        if (isPrime(x))
        {
            fprintf(fprime, "%d\n", x);
        }
    }
    fclose(p);
    fclose(fprime);
    return 0;
}