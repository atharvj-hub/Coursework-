#include<stdio.h>
 
int main()
{
    long long n;
    int fib[62], i;
    printf("Enter n: ");
    scanf("%lld", &n);
    fib[0] = 0;
    fib[1] = 1;
    for(i = 2; i <= 61; i++)
        fib[i] = (fib[i-1] + fib[i-2]) % 10;
    long long rem = (n + 2) % 60;
    int lastDigit = (fib[rem] - 1 + 10) % 10;
    printf("Last digit of sum of F(0) to F(%lld) = %d\n", n, lastDigit);
    return 0;
}
