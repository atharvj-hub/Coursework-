// ============================================================
// PROGRAM 1: Factorial of a given number
// ============================================================

#include<stdio.h>

int main()
{
    int n, i;
    long long fact = 1;
    printf("Enter a number: ");
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
        fact = fact * i;
    printf("Factorial of %d = %lld\n", n, fact);
    return 0;
}

// ============================================================
// PROGRAM 2: Fibonacci series
// ============================================================

#include<stdio.h>

int main()
{
    int n, i;
    long long a = 0, b = 1, c;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Fibonacci Series: ");
    for(i = 0; i < n; i++)
    {
        printf("%lld ", a);
        c = a + b;
        a = b;
        b = c;
    }
    printf("\n");
    return 0;
}

// ============================================================
// PROGRAM 3: Last Digit of a Large Fibonacci Number
// ============================================================

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

// ============================================================
// PROGRAM 4: Last Digit of the Sum of Fibonacci Numbers
// ============================================================

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

// ============================================================
// PROGRAM 5: Number of ways a given word can be scrambled
// ============================================================

#include<stdio.h>
#include<string.h>

long long fact(int n)
{
    if(n <= 1)
        return 1;
    return n * fact(n - 1);
}

int main()
{
    char word[100];
    int freq[26] = {0}, i, len;
    printf("Enter a word: ");
    scanf("%s", word);
    len = strlen(word);
    for(i = 0; i < len; i++)
        freq[word[i] - 'a']++;
    long long result = fact(len);
    for(i = 0; i < 26; i++)
        result /= fact(freq[i]);
    printf("Number of ways to scramble \"%s\" = %lld\n", word, result);
    return 0;
}

// ============================================================
// PROGRAM 6: Money Change Problem
// ============================================================

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

// ============================================================
// PROGRAM 7: Sum of array elements
// ============================================================

#include<stdio.h>

int main()
{
    int n, i, sum = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for(i = 0; i < n; i++)
        sum += arr[i];
    printf("Sum of array elements = %d\n", sum);
    return 0;
}

// ============================================================
// PROGRAM 8: Insert element at given location in array
// ============================================================

#include<stdio.h>

int main()
{
    int n, pos, val, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n + 1];
    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter position to insert (1 to %d): ", n + 1);
    scanf("%d", &pos);
    printf("Enter value to insert: ");
    scanf("%d", &val);
    for(i = n; i >= pos; i--)
        arr[i] = arr[i - 1];
    arr[pos - 1] = val;
    n++;
    printf("Array after insertion: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}

// ============================================================
// PROGRAM 9: Insert element in sorted array
// ============================================================

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

// ============================================================
// PROGRAM 10: Delete element from given location in array
// ============================================================

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

// ============================================================
// PROGRAM 11: Linear Search
// ============================================================

#include<stdio.h>

int main()
{
    int n, key, i, found = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter element to search: ");
    scanf("%d", &key);
    for(i = 0; i < n; i++)
    {
        if(arr[i] == key)
        {
            printf("Element %d found at position %d\n", key, i + 1);
            found = 1;
        }
    }
    if(!found)
        printf("Element not found\n");
    return 0;
}

// ============================================================
// PROGRAM 12: Largest element and its location
// ============================================================

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

// ============================================================
// PROGRAM 13: Largest and Second Largest element
// ============================================================

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

// ============================================================
// PROGRAM 14: Binary Search
// ============================================================

#include<stdio.h>

int main()
{
    int n, key, low, high, mid, pos = -1, i;
    printf("Enter number of elements in sorted array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter sorted elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter element to search: ");
    scanf("%d", &key);
    low = 0;
    high = n - 1;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(arr[mid] == key)
        {
            pos = mid;
            break;
        }
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    if(pos != -1)
        printf("Element %d found at position %d\n", key, pos + 1);
    else
        printf("Element not found\n");
    return 0;
}

// ============================================================
// PROGRAM 15: Bubble Sort
// ============================================================

#include<stdio.h>

int main()
{
    int n, i, j, temp;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - 1 - i; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Sorted array: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}

// ============================================================
// PROGRAM 16: Sum of elements in one-way linked list
// ============================================================

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* createNode(int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main()
{
    int n, val, sum = 0;
    struct Node *head = NULL, *temp = NULL, *newNode;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        newNode = createNode(val);
        if(head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    temp = head;
    while(temp != NULL)
    {
        sum += temp->data;
        temp = temp->next;
    }
    printf("Sum of linked list elements = %d\n", sum);
    return 0;
}

// ============================================================
// PROGRAM 17: Find location of element in one-way linked list
// ============================================================

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* createNode(int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main()
{
    int n, val, key, pos = 1, found = 0;
    struct Node *head = NULL, *temp = NULL, *newNode;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        newNode = createNode(val);
        if(head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    printf("Enter element to search: ");
    scanf("%d", &key);
    temp = head;
    while(temp != NULL)
    {
        if(temp->data == key)
        {
            printf("Element %d found at position %d\n", key, pos);
            found = 1;
        }
        temp = temp->next;
        pos++;
    }
    if(!found)
        printf("Element not found\n");
    return 0;
}

// ============================================================
// PROGRAM 18: Insert at beginning of one-way linked list
// ============================================================

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* createNode(int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void display(struct Node *head)
{
    struct Node *temp = head;
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int n, val;
    struct Node *head = NULL, *temp = NULL, *newNode;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        newNode = createNode(val);
        if(head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    printf("Original list: ");
    display(head);
    printf("Enter element to insert at beginning: ");
    scanf("%d", &val);
    newNode = createNode(val);
    newNode->next = head;
    head = newNode;
    printf("List after insertion: ");
    display(head);
    return 0;
}

// ============================================================
// PROGRAM 19: Insert at end of one-way linked list
// ============================================================

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* createNode(int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void display(struct Node *head)
{
    struct Node *temp = head;
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int n, val;
    struct Node *head = NULL, *temp = NULL, *newNode;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        newNode = createNode(val);
        if(head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    printf("Original list: ");
    display(head);
    printf("Enter element to insert at end: ");
    scanf("%d", &val);
    newNode = createNode(val);
    if(head == NULL)
        head = newNode;
    else
    {
        temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("List after insertion: ");
    display(head);
    return 0;
}

// ============================================================
// PROGRAM 20: Insert after given node (position) in one-way linked list
// ============================================================

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* createNode(int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void display(struct Node *head)
{
    struct Node *temp = head;
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int n, val, pos, i;
    struct Node *head = NULL, *temp = NULL, *newNode;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &val);
        newNode = createNode(val);
        if(head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    printf("Original list: ");
    display(head);
    printf("Enter position after which to insert: ");
    scanf("%d", &pos);
    printf("Enter value to insert: ");
    scanf("%d", &val);
    temp = head;
    for(i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;
    if(temp == NULL)
        printf("Invalid position\n");
    else
    {
        newNode = createNode(val);
        newNode->next = temp->next;
        temp->next = newNode;
        printf("List after insertion: ");
        display(head);
    }
    return 0;
}

// ============================================================
// PROGRAM 21: Insert after given element in one-way linked list
// ============================================================

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* createNode(int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void display(struct Node *head)
{
    struct Node *temp = head;
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int n, val, key;
    struct Node *head = NULL, *temp = NULL, *newNode;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        newNode = createNode(val);
        if(head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    printf("Original list: ");
    display(head);
    printf("Enter element after which to insert: ");
    scanf("%d", &key);
    printf("Enter value to insert: ");
    scanf("%d", &val);
    temp = head;
    while(temp != NULL && temp->data != key)
        temp = temp->next;
    if(temp == NULL)
        printf("Element not found\n");
    else
    {
        newNode = createNode(val);
        newNode->next = temp->next;
        temp->next = newNode;
        printf("List after insertion: ");
        display(head);
    }
    return 0;
}

// ============================================================
// PROGRAM 22: Insert in sorted one-way linked list
// ============================================================

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* createNode(int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void display(struct Node *head)
{
    struct Node *temp = head;
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int n, val;
    struct Node *head = NULL, *temp = NULL, *newNode;
    printf("Enter number of elements in sorted list: ");
    scanf("%d", &n);
    printf("Enter sorted elements: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        newNode = createNode(val);
        if(head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    printf("Original sorted list: ");
    display(head);
    printf("Enter value to insert: ");
    scanf("%d", &val);
    newNode = createNode(val);
    if(head == NULL || val < head->data)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        temp = head;
        while(temp->next != NULL && temp->next->data < val)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("Sorted list after insertion: ");
    display(head);
    return 0;
}

// ============================================================
// PROGRAM 23: Delete first node from one-way linked list
// ============================================================

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* createNode(int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void display(struct Node *head)
{
    struct Node *temp = head;
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int n, val;
    struct Node *head = NULL, *temp = NULL, *newNode;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        newNode = createNode(val);
        if(head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    printf("Original list: ");
    display(head);
    if(head == NULL)
        printf("List is empty\n");
    else
    {
        temp = head;
        head = head->next;
        printf("Deleted node: %d\n", temp->data);
        free(temp);
        printf("List after deletion: ");
        display(head);
    }
    return 0;
}

// ============================================================
// PROGRAM 24: Delete last node from one-way linked list
// ============================================================

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* createNode(int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void display(struct Node *head)
{
    struct Node *temp = head;
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int n, val;
    struct Node *head = NULL, *temp = NULL, *prev = NULL, *newNode;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        newNode = createNode(val);
        if(head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    printf("Original list: ");
    display(head);
    if(head == NULL)
        printf("List is empty\n");
    else if(head->next == NULL)
    {
        printf("Deleted node: %d\n", head->data);
        free(head);
        head = NULL;
        printf("List is now empty\n");
    }
    else
    {
        temp = head;
        while(temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        printf("Deleted node: %d\n", temp->data);
        prev->next = NULL;
        free(temp);
        printf("List after deletion: ");
        display(head);
    }
    return 0;
}

// ============================================================
// PROGRAM 25: Delete given element from one-way linked list
// ============================================================

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* createNode(int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void display(struct Node *head)
{
    struct Node *temp = head;
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int n, val, key;
    struct Node *head = NULL, *temp = NULL, *prev = NULL, *newNode;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        newNode = createNode(val);
        if(head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    printf("Original list: ");
    display(head);
    printf("Enter element to delete: ");
    scanf("%d", &key);
    temp = head;
    prev = NULL;
    while(temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL)
        printf("Element not found\n");
    else
    {
        if(prev == NULL)
            head = head->next;
        else
            prev->next = temp->next;
        printf("Deleted element: %d\n", temp->data);
        free(temp);
        printf("List after deletion: ");
        display(head);
    }
    return 0;
}

// ============================================================
// PROGRAM 26: Sum of elements in two-way linked list
// ============================================================

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node* createNode(int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

int main()
{
    int n, val, sum = 0;
    struct Node *head = NULL, *temp = NULL, *newNode;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        newNode = createNode(val);
        if(head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            newNode->prev = temp;
            temp->next = newNode;
            temp = temp->next;
        }
    }
    temp = head;
    while(temp != NULL)
    {
        sum += temp->data;
        temp = temp->next;
    }
    printf("Sum of two-way linked list elements = %d\n", sum);
    return 0;
}

// ============================================================
// PROGRAM 27: Insert element in two-way linked list
// ============================================================

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node* createNode(int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void display(struct Node *head)
{
    struct Node *temp = head;
    while(temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int n, val, pos, i;
    struct Node *head = NULL, *temp = NULL, *newNode;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &val);
        newNode = createNode(val);
        if(head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            newNode->prev = temp;
            temp->next = newNode;
            temp = temp->next;
        }
    }
    printf("Original list: ");
    display(head);
    printf("Enter position to insert (1 to %d): ", n + 1);
    scanf("%d", &pos);
    printf("Enter value to insert: ");
    scanf("%d", &val);
    newNode = createNode(val);
    if(pos == 1)
    {
        newNode->next = head;
        if(head != NULL)
            head->prev = newNode;
        head = newNode;
    }
    else
    {
        temp = head;
        for(i = 1; i < pos - 1 && temp != NULL; i++)
            temp = temp->next;
        if(temp != NULL)
        {
            newNode->next = temp->next;
            newNode->prev = temp;
            if(temp->next != NULL)
                temp->next->prev = newNode;
            temp->next = newNode;
        }
    }
    printf("List after insertion: ");
    display(head);
    return 0;
}

// ============================================================
// PROGRAM 28: Delete element from two-way linked list
// ============================================================

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node* createNode(int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void display(struct Node *head)
{
    struct Node *temp = head;
    while(temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int n, val, key;
    struct Node *head = NULL, *temp = NULL, *newNode;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        newNode = createNode(val);
        if(head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            newNode->prev = temp;
            temp->next = newNode;
            temp = temp->next;
        }
    }
    printf("Original list: ");
    display(head);
    printf("Enter element to delete: ");
    scanf("%d", &key);
    temp = head;
    while(temp != NULL && temp->data != key)
        temp = temp->next;
    if(temp == NULL)
        printf("Element not found\n");
    else
    {
        if(temp->prev != NULL)
            temp->prev->next = temp->next;
        else
            head = temp->next;
        if(temp->next != NULL)
            temp->next->prev = temp->prev;
        printf("Deleted element: %d\n", temp->data);
        free(temp);
        printf("List after deletion: ");
        display(head);
    }
    return 0;
}

// ============================================================
// PROGRAM 29: Stack PUSH and POP using Array
// ============================================================

#include<stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int val)
{
    if(top == MAX - 1)
        printf("Stack Overflow\n");
    else
    {
        top++;
        stack[top] = val;
        printf("%d pushed to stack\n", val);
    }
}

int pop()
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

void display()
{
    if(top == -1)
        printf("Stack is empty\n");
    else
    {
        printf("Stack (top to bottom): ");
        for(int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

int main()
{
    int choice, val;
    while(1)
    {
        printf("\n1. Push  2. Pop  3. Display  4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                val = pop();
                if(val != -1)
                    printf("Popped: %d\n", val);
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

// ============================================================
// PROGRAM 30: Stack PUSH and POP using Linked List
// ============================================================

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int val)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = top;
    top = newNode;
    printf("%d pushed to stack\n", val);
}

int pop()
{
    if(top == NULL)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    struct Node *temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

void display()
{
    if(top == NULL)
        printf("Stack is empty\n");
    else
    {
        struct Node *temp = top;
        printf("Stack (top to bottom): ");
        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    int choice, val;
    while(1)
    {
        printf("\n1. Push  2. Pop  3. Display  4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                val = pop();
                if(val != -1)
                    printf("Popped: %d\n", val);
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

// ============================================================
// PROGRAM 31: Infix to Postfix Conversion
// ============================================================

#include<stdio.h>
#include<string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) { stack[++top] = c; }

char pop() { return (top == -1) ? -1 : stack[top--]; }

int precedence(char c)
{
    if(c == '+' || c == '-') return 1;
    if(c == '*' || c == '/') return 2;
    if(c == '^') return 3;
    return 0;
}

int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int main()
{
    char infix[MAX], postfix[MAX];
    int i, j = 0, len;
    printf("Enter infix expression: ");
    scanf("%s", infix);
    len = strlen(infix);
    for(i = 0; i < len; i++)
    {
        char c = infix[i];
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            postfix[j++] = c;
        else if(c == '(')
            push(c);
        else if(c == ')')
        {
            while(top != -1 && stack[top] != '(')
                postfix[j++] = pop();
            pop();
        }
        else if(isOperator(c))
        {
            while(top != -1 && precedence(stack[top]) >= precedence(c))
                postfix[j++] = pop();
            push(c);
        }
    }
    while(top != -1)
        postfix[j++] = pop();
    postfix[j] = '\0';
    printf("Postfix expression: %s\n", postfix);
    return 0;
}

// ============================================================
// PROGRAM 32: Queue Enqueue and Dequeue using Array
// ============================================================

#include<stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int val)
{
    if(rear == MAX - 1)
        printf("Queue Overflow\n");
    else
    {
        if(front == -1)
            front = 0;
        rear++;
        queue[rear] = val;
        printf("%d enqueued\n", val);
    }
}

int dequeue()
{
    if(front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        return -1;
    }
    return queue[front++];
}

void display()
{
    if(front == -1 || front > rear)
        printf("Queue is empty\n");
    else
    {
        printf("Queue (front to rear): ");
        for(int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main()
{
    int choice, val;
    while(1)
    {
        printf("\n1. Enqueue  2. Dequeue  3. Display  4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                val = dequeue();
                if(val != -1)
                    printf("Dequeued: %d\n", val);
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

// ============================================================
// PROGRAM 33: Queue Enqueue and Dequeue using Linked List
// ============================================================

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL, *rear = NULL;

void enqueue(int val)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if(rear == NULL)
        front = rear = newNode;
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d enqueued\n", val);
}

int dequeue()
{
    if(front == NULL)
    {
        printf("Queue Underflow\n");
        return -1;
    }
    struct Node *temp = front;
    int val = temp->data;
    front = front->next;
    if(front == NULL)
        rear = NULL;
    free(temp);
    return val;
}

void display()
{
    if(front == NULL)
        printf("Queue is empty\n");
    else
    {
        struct Node *temp = front;
        printf("Queue (front to rear): ");
        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    int choice, val;
    while(1)
    {
        printf("\n1. Enqueue  2. Dequeue  3. Display  4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                val = dequeue();
                if(val != -1)
                    printf("Dequeued: %d\n", val);
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

// ============================================================
// PROGRAM 34: Quick Sort
// ============================================================

#include<stdio.h>

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1, j, temp;
    for(j = low; j < high; j++)
    {
        if(arr[j] <= pivot)
        {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    quickSort(arr, 0, n - 1);
    printf("Sorted array: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}

// ============================================================
// PROGRAM 35: Binary Search Tree (BST) using Linked List
// ============================================================

#include<stdio.h>
#include<stdlib.h>

struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createTreeNode(int data)
{
    struct TreeNode *newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* insert(struct TreeNode *root, int data)
{
    if(root == NULL)
        return createTreeNode(data);
    if(data < root->data)
        root->left = insert(root->left, data);
    else if(data > root->data)
        root->right = insert(root->right, data);
    return root;
}

int search(struct TreeNode *root, int key)
{
    if(root == NULL)
        return 0;
    if(root->data == key)
        return 1;
    if(key < root->data)
        return search(root->left, key);
    return search(root->right, key);
}

void inorder(struct TreeNode *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{
    int n, val, key;
    struct TreeNode *root = NULL;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        root = insert(root, val);
    }
    printf("BST Inorder Traversal: ");
    inorder(root);
    printf("\n");
    printf("Enter element to search: ");
    scanf("%d", &key);
    if(search(root, key))
        printf("%d found in BST\n", key);
    else
        printf("%d not found in BST\n", key);
    return 0;
}

// ============================================================
// PROGRAM 36: BST Traversals - Pre-order, In-order, Post-order
// ============================================================

#include<stdio.h>
#include<stdlib.h>

struct BSTNode2
{
    int data;
    struct BSTNode2 *left;
    struct BSTNode2 *right;
};

struct BSTNode2* createBstNode2(int data)
{
    struct BSTNode2 *newNode = (struct BSTNode2*)malloc(sizeof(struct BSTNode2));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct BSTNode2* insertBst2(struct BSTNode2 *root, int data)
{
    if(root == NULL)
        return createBstNode2(data);
    if(data < root->data)
        root->left = insertBst2(root->left, data);
    else if(data > root->data)
        root->right = insertBst2(root->right, data);
    return root;
}

void preorderBst2(struct BSTNode2 *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preorderBst2(root->left);
        preorderBst2(root->right);
    }
}

void inorderBst2(struct BSTNode2 *root)
{
    if(root != NULL)
    {
        inorderBst2(root->left);
        printf("%d ", root->data);
        inorderBst2(root->right);
    }
}

void postorderBst2(struct BSTNode2 *root)
{
    if(root != NULL)
    {
        postorderBst2(root->left);
        postorderBst2(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    int n, val;
    struct BSTNode2 *root = NULL;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        root = insertBst2(root, val);
    }
    printf("Pre-order Traversal:  ");
    preorderBst2(root);
    printf("\nIn-order Traversal:   ");
    inorderBst2(root);
    printf("\nPost-order Traversal: ");
    postorderBst2(root);
    printf("\n");
    return 0;
}

// ============================================================
// PROGRAM 37: Graph using Adjacency Matrix
// ============================================================

#include<stdio.h>
#define MAX 10

int graph[MAX][MAX];
int vertices;

void addEdge(int u, int v)
{
    graph[u][v] = 1;
    graph[v][u] = 1;
}

void display()
{
    int i, j;
    printf("Adjacency Matrix:\n");
    printf("  ");
    for(i = 0; i < vertices; i++)
        printf("%d ", i);
    printf("\n");
    for(i = 0; i < vertices; i++)
    {
        printf("%d ", i);
        for(j = 0; j < vertices; j++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }
}

int main()
{
    int edges, u, v, i, j;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    for(i = 0; i < vertices; i++)
        for(j = 0; j < vertices; j++)
            graph[i][j] = 0;
    printf("Enter edges (u v):\n");
    for(i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }
    display();
    return 0;
}

// ============================================================
// PROGRAM 38: Insertion Sort
// ============================================================

#include<stdio.h>

int main()
{
    int n, i, j, key;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for(i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    printf("Sorted array: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}

// ============================================================
// PROGRAM 39: Selection Sort
// ============================================================

#include<stdio.h>

int main()
{
    int n, i, j, minIdx, temp;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for(i = 0; i < n - 1; i++)
    {
        minIdx = i;
        for(j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[minIdx])
                minIdx = j;
        }
        temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
    printf("Sorted array: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}

// ============================================================
// PROGRAM 40: Merge Sort
// ============================================================

#include<stdio.h>

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2], i, j, k;
    for(i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    i = 0;
    j = 0;
    k = left;
    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while(i < n1)
        arr[k++] = L[i++];
    while(j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right)
{
    if(left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main()
{
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    mergeSort(arr, 0, n - 1);
    printf("Sorted array: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}