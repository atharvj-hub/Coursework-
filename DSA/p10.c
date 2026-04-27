#include<stdio.h>
 
int main()
{
    int n, pos, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter position to delete (1 to %d): ", n);
    scanf("%d", &pos);
    printf("Deleted element: %d\n", arr[pos - 1]);
    for(i = pos - 1; i < n - 1; i++)
        arr[i] = arr[i + 1];
    n--;
    printf("Array after deletion: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
