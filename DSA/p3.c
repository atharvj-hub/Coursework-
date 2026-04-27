#include<stdio.h>
 
int main()
{
    long long n;
    int fib[61], i;
    printf("Enter n: ");
    scanf("%lld", &n);
    fib[0] = 0;
    fib[1] = 1;
    for(i = 2; i <= 60; i++)
        fib[i] = (fib[i-1] + fib[i-2]) % 10;
    int rem = (int)(n % 60);
    printf("Last digit of F(%lld) = %d\n", n, fib[rem]);
    return 0;
}
