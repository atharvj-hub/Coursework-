#include<stdio.h>
 
int main()
{
    int n, i, max, pos;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    max = arr[0];
    pos = 0;
    for(i = 1; i < n; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
            pos = i;
        }
    }
    printf("Largest element: %d\n", max);
    printf("Location: %d\n", pos + 1);
    return 0;
}
