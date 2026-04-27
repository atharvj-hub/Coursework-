#include<stdio.h>
 
int main()
{
    int n, val, i, pos;
    printf("Enter number of elements in sorted array: ");
    scanf("%d", &n);
    int arr[n + 1];
    printf("Enter sorted elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter value to insert: ");
    scanf("%d", &val);
    pos = n;
    for(i = 0; i < n; i++)
    {
        if(val < arr[i])
        {
            pos = i;
            break;
        }
    }
    for(i = n; i > pos; i--)
        arr[i] = arr[i - 1];
    arr[pos] = val;
    n++;
    printf("Sorted array after insertion: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
