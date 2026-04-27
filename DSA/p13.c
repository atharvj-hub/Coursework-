#include<stdio.h>
#include<limits.h>
 
int main()
{
    int n, i, first, second;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    first = arr[0];
    second = INT_MIN;
    for(i = 1; i < n; i++)
    {
        if(arr[i] > first)
        {
            second = first;
            first = arr[i];
        }
        else if(arr[i] > second && arr[i] != first)
            second = arr[i];
    }
    printf("Largest element: %d\n", first);
    printf("Second largest element: %d\n", second);
    return 0;
}
