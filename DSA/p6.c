#include<stdio.h>
 
int main()
{
    int coins[] = {500, 100, 50, 20, 10, 5, 2, 1};
    int n = 8, amount, i;
    printf("Enter the amount: ");
    scanf("%d", &amount);
    printf("Change for %d:\n", amount);
    for(i = 0; i < n; i++)
    {
        if(amount >= coins[i])
        {
            int count = amount / coins[i];
            printf("%d x %d = %d\n", count, coins[i], count * coins[i]);
            amount = amount % coins[i];
        }
    }
    return 0;
}
