#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX 100

// ==========================================
// DATA STRUCTURE DEFINITIONS
// ==========================================

// Singly Linked List Node
struct SNode {
    int data;
    struct SNode *next;
};

// Doubly Linked List Node
struct DNode {
    int data;
    struct DNode *prev;
    struct DNode *next;
};

// Binary Search Tree Node
struct TNode {
    int data;
    struct TNode *left;
    struct TNode *right;
};

// ==========================================
// HELPER FUNCTIONS
// ==========================================

// --- Math & Misc Helpers ---
long long factorial(int n) {
    if(n <= 1) return 1;
    return n * factorial(n - 1);
}

// --- Node Creation Helpers ---
struct SNode* createSNode(int data) {
    struct SNode *newNode = (struct SNode*)malloc(sizeof(struct SNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct DNode* createDNode(int data) {
    struct DNode *newNode = (struct DNode*)malloc(sizeof(struct DNode));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

struct TNode* createTNode(int data) {
    struct TNode *newNode = (struct TNode*)malloc(sizeof(struct TNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// --- Display Helpers ---
void displaySLL(struct SNode *head) {
    while(head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void displayDLL(struct DNode *head) {
    while(head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// --- BST Helpers ---
struct TNode* insertBST(struct TNode *root, int data) {
    if(root == NULL) return createTNode(data);
    if(data < root->data) root->left = insertBST(root->left, data);
    else if(data > root->data) root->right = insertBST(root->right, data);
    return root;
}

void inorderBST(struct TNode *root) {
    if(root != NULL) {
        inorderBST(root->left);
        printf("%d ", root->data);
        inorderBST(root->right);
    }
}

void preorderBST(struct TNode *root) {
    if(root != NULL) {
        printf("%d ", root->data);
        preorderBST(root->left);
        preorderBST(root->right);
    }
}

void postorderBST(struct TNode *root) {
    if(root != NULL) {
        postorderBST(root->left);
        postorderBST(root->right);
        printf("%d ", root->data);
    }
}

// --- Stack (Array) Global Variables ---
int stack_arr[MAX];
int top_arr = -1;

void push_arr(int val) {
    if(top_arr == MAX - 1) printf("Stack Overflow\n");
    else { stack_arr[++top_arr] = val; printf("%d pushed to stack\n", val); }
}

int pop_arr() {
    if(top_arr == -1) { printf("Stack Underflow\n"); return -1; }
    return stack_arr[top_arr--];
}

// --- Stack (Linked List) Global Variables ---
struct SNode *top_ll = NULL;

void push_ll(int val) {
    struct SNode *newNode = createSNode(val);
    newNode->next = top_ll;
    top_ll = newNode;
    printf("%d pushed to stack\n", val);
}

int pop_ll() {
    if(top_ll == NULL) { printf("Stack Underflow\n"); return -1; }
    struct SNode *temp = top_ll;
    int val = temp->data;
    top_ll = top_ll->next;
    free(temp);
    return val;
}

// --- Queue (Array) Global Variables ---
int queue_arr[MAX];
int front_arr = -1, rear_arr = -1;

void enqueue_arr(int val) {
    if(rear_arr == MAX - 1) printf("Queue Overflow\n");
    else {
        if(front_arr == -1) front_arr = 0;
        queue_arr[++rear_arr] = val;
        printf("%d enqueued\n", val);
    }
}

int dequeue_arr() {
    if(front_arr == -1 || front_arr > rear_arr) { printf("Queue Underflow\n"); return -1; }
    return queue_arr[front_arr++];
}

// --- Queue (Linked List) Global Variables ---
struct SNode *front_ll = NULL, *rear_ll = NULL;

void enqueue_ll(int val) {
    struct SNode *newNode = createSNode(val);
    if(rear_ll == NULL) front_ll = rear_ll = newNode;
    else { rear_ll->next = newNode; rear_ll = newNode; }
    printf("%d enqueued\n", val);
}

int dequeue_ll() {
    if(front_ll == NULL) { printf("Queue Underflow\n"); return -1; }
    struct SNode *temp = front_ll;
    int val = temp->data;
    front_ll = front_ll->next;
    if(front_ll == NULL) rear_ll = NULL;
    free(temp);
    return val;
}

// --- Graph Matrix Global ---
int graph[10][10];
int vertices;
void addEdge(int u, int v) {
    graph[u][v] = 1; graph[v][u] = 1;
}

static void qSort(int a[], int l, int h) {
    if(l < h) {
        int pivot = a[h], i_idx = l - 1, temp;
        for(int j = l; j < h; j++) {
            if(a[j] <= pivot) { i_idx++; temp = a[i_idx]; a[i_idx] = a[j]; a[j] = temp; }
        }
        temp = a[i_idx + 1]; a[i_idx + 1] = a[h]; a[h] = temp;
        int pi = i_idx + 1;
        qSort(a, l, pi - 1); qSort(a, pi + 1, h);
    }
}

static int searchBST(struct TNode *r, int k) {
    if(r == NULL) return 0;
    if(r->data == k) return 1;
    if(k < r->data) return searchBST(r->left, k);
    return searchBST(r->right, k);
}

static void m_merge(int a[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m, L[n1], R[n2], idx1=0, idx2=0, k=l;
    for(int x=0; x<n1; x++) L[x] = a[l+x];
    for(int y=0; y<n2; y++) R[y] = a[m+1+y];
    while(idx1<n1 && idx2<n2) { if(L[idx1]<=R[idx2]) a[k++] = L[idx1++]; else a[k++] = R[idx2++]; }
    while(idx1<n1) a[k++] = L[idx1++];
    while(idx2<n2) a[k++] = R[idx2++];
}

static void m_sort(int a[], int l, int r) {
    if(l < r) {
        int m = (l + r) / 2;
        m_sort(a, l, m); m_sort(a, m + 1, r); m_merge(a, l, m, r);
    }
}

// ==========================================
// MAIN MENU-DRIVEN PROGRAM
// ==========================================
int main() {
    int choice;

    while (1) {
        printf("\n======================================================\n");
        printf("         DATA STRUCTURES & ALGORITHMS LAB MENU          \n");
        printf("======================================================\n");
        printf(" 1. Factorial of a number\n");
        printf(" 2. Fibonacci series\n");
        printf(" 3. Last Digit of a Large Fibonacci Number\n");
        printf(" 4. Last Digit of the Sum of Fibonacci Numbers\n");
        printf(" 5. Numbers of ways a word can be scrambled\n");
        printf(" 6. Money Change Problem\n");
        printf(" 7. Sum of array elements\n");
        printf(" 8. Insert element at a given location in an array\n");
        printf(" 9. Insert element in the sorted array\n");
        printf("10. Delete element from a given location of array\n");
        printf("11. Linear Search in an array\n");
        printf("12. Largest element from an array and its location\n");
        printf("13. Largest and second largest element from an array\n");
        printf("14. Binary Search in an array\n");
        printf("15. Bubble Sort\n");
        printf("16. Sum of elements stored in one-way linked list\n");
        printf("17. Find location of an element in one-way linked list\n");
        printf("18. Insert element at the beginning of one-way linked list\n");
        printf("19. Insert element at the end of one-way linked list\n");
        printf("20. Insert element after a given node in one-way linked list\n");
        printf("21. Insert element after a given element in one-way linked list\n");
        printf("22. Insert element in a sorted one-way linked list\n");
        printf("23. Delete the first node from one-way linked list\n");
        printf("24. Delete the last node from one-way linked list\n");
        printf("25. Delete a given element from one-way linked list\n");
        printf("26. Sum of elements stored in two-way linked list\n");
        printf("27. Insert a given element in two-way linked list\n");
        printf("28. Delete a given element from two-way linked list\n");
        printf("29. Stack operations (PUSH, POP) using array\n");
        printf("30. Stack operations (PUSH, POP) using Linked List\n");
        printf("31. Infix expression to Postfix conversion\n");
        printf("32. Queue operations (Enqueue, Dequeue) using array\n");
        printf("33. Queue operations (Enqueue, Dequeue) using Linked List\n");
        printf("34. Quick Sort\n");
        printf("35. Binary Search Tree (Insert & Search)\n");
        printf("36. BST Traversals (Pre/In/Post order)\n");
        printf("37. Graph using adjacency matrix\n");
        printf("38. Insertion Sort\n");
        printf("39. Selection Sort\n");
        printf("40. Merge Sort\n");
        printf(" 0. EXIT\n");
        printf("======================================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Exiting program...\n");
            break;
        }

        switch(choice) {
            case 1: {
                int n, i; long long fact = 1;
                printf("Enter a number: "); scanf("%d", &n);
                for(i = 1; i <= n; i++) fact = fact * i;
                printf("Factorial of %d = %lld\n", n, fact);
                break;
            }
            case 2: {
                int n, i; long long a = 0, b = 1, c;
                printf("Enter the number of terms: "); scanf("%d", &n);
                printf("Fibonacci Series: ");
                for(i = 0; i < n; i++) {
                    printf("%lld ", a);
                    c = a + b; a = b; b = c;
                }
                printf("\n");
                break;
            }
            case 3: {
                long long n; int fib[61], i;
                printf("Enter n: "); scanf("%lld", &n);
                fib[0] = 0; fib[1] = 1;
                for(i = 2; i <= 60; i++) fib[i] = (fib[i-1] + fib[i-2]) % 10;
                int rem = (int)(n % 60);
                printf("Last digit of F(%lld) = %d\n", n, fib[rem]);
                break;
            }
            case 4: {
                long long n; int fib[62], i;
                printf("Enter n: "); scanf("%lld", &n);
                fib[0] = 0; fib[1] = 1;
                for(i = 2; i <= 61; i++) fib[i] = (fib[i-1] + fib[i-2]) % 10;
                long long rem = (n + 2) % 60;
                int lastDigit = (fib[rem] - 1 + 10) % 10;
                printf("Last digit of sum of F(0) to F(%lld) = %d\n", n, lastDigit);
                break;
            }
            case 5: {
                char word[100]; int freq[26] = {0}, i, len;
                printf("Enter a word: "); scanf("%s", word);
                len = strlen(word);
                for(i = 0; i < len; i++) freq[word[i] - 'a']++;
                long long result = factorial(len);
                for(i = 0; i < 26; i++) result /= factorial(freq[i]);
                printf("Number of ways to scramble \"%s\" = %lld\n", word, result);
                break;
            }
            case 6: {
                int coins[] = {500, 100, 50, 20, 10, 5, 2, 1};
                int n = 8, amount, i;
                printf("Enter the amount: "); scanf("%d", &amount);
                printf("Change for %d:\n", amount);
                for(i = 0; i < n; i++) {
                    if(amount >= coins[i]) {
                        int count = amount / coins[i];
                        printf("%d x %d = %d\n", count, coins[i], count * coins[i]);
                        amount = amount % coins[i];
                    }
                }
                break;
            }
            case 7: {
                int n, i, sum = 0;
                printf("Enter the number of elements: "); scanf("%d", &n);
                int arr[n];
                printf("Enter elements: ");
                for(i = 0; i < n; i++) { scanf("%d", &arr[i]); sum += arr[i]; }
                printf("Sum of array elements = %d\n", sum);
                break;
            }
            case 8: {
                int n, pos, val, i;
                printf("Enter the number of elements: "); scanf("%d", &n);
                int arr[n + 1];
                printf("Enter elements: ");
                for(i = 0; i < n; i++) scanf("%d", &arr[i]);
                printf("Enter position to insert (1 to %d): ", n + 1); scanf("%d", &pos);
                printf("Enter value to insert: "); scanf("%d", &val);
                for(i = n; i >= pos; i--) arr[i] = arr[i - 1];
                arr[pos - 1] = val; n++;
                printf("Array after insertion: ");
                for(i = 0; i < n; i++) printf("%d ", arr[i]);
                printf("\n");
                break;
            }
            case 9: {
                int n, val, i, pos;
                printf("Enter number of elements in sorted array: "); scanf("%d", &n);
                int arr[n + 1];
                printf("Enter sorted elements: ");
                for(i = 0; i < n; i++) scanf("%d", &arr[i]);
                printf("Enter value to insert: "); scanf("%d", &val);
                pos = n;
                for(i = 0; i < n; i++) { if(val < arr[i]) { pos = i; break; } }
                for(i = n; i > pos; i--) arr[i] = arr[i - 1];
                arr[pos] = val; n++;
                printf("Sorted array after insertion: ");
                for(i = 0; i < n; i++) printf("%d ", arr[i]);
                printf("\n");
                break;
            }
            case 10: {
                int n, pos, i;
                printf("Enter number of elements: "); scanf("%d", &n);
                int arr[n];
                printf("Enter elements: ");
                for(i = 0; i < n; i++) scanf("%d", &arr[i]);
                printf("Enter position to delete (1 to %d): ", n); scanf("%d", &pos);
                printf("Deleted element: %d\n", arr[pos - 1]);
                for(i = pos - 1; i < n - 1; i++) arr[i] = arr[i + 1];
                n--;
                printf("Array after deletion: ");
                for(i = 0; i < n; i++) printf("%d ", arr[i]);
                printf("\n");
                break;
            }
            case 11: {
                int n, key, i, found = 0;
                printf("Enter number of elements: "); scanf("%d", &n);
                int arr[n];
                printf("Enter elements: ");
                for(i = 0; i < n; i++) scanf("%d", &arr[i]);
                printf("Enter element to search: "); scanf("%d", &key);
                for(i = 0; i < n; i++) {
                    if(arr[i] == key) {
                        printf("Element %d found at position %d\n", key, i + 1);
                        found = 1;
                    }
                }
                if(!found) printf("Element not found\n");
                break;
            }
            case 12: {
                int n, i, max, pos = 0;
                printf("Enter number of elements: "); scanf("%d", &n);
                int arr[n];
                printf("Enter elements: ");
                for(i = 0; i < n; i++) scanf("%d", &arr[i]);
                max = arr[0];
                for(i = 1; i < n; i++) {
                    if(arr[i] > max) { max = arr[i]; pos = i; }
                }
                printf("Largest element: %d\nLocation: %d\n", max, pos + 1);
                break;
            }
            case 13: {
                int n, i, first, second;
                printf("Enter number of elements: "); scanf("%d", &n);
                int arr[n];
                printf("Enter elements: ");
                for(i = 0; i < n; i++) scanf("%d", &arr[i]);
                first = arr[0]; second = INT_MIN;
                for(i = 1; i < n; i++) {
                    if(arr[i] > first) { second = first; first = arr[i]; }
                    else if(arr[i] > second && arr[i] != first) second = arr[i];
                }
                printf("Largest element: %d\nSecond largest element: %d\n", first, second);
                break;
            }
            case 14: {
                int n, key, low, high, mid, pos = -1, i;
                printf("Enter number of elements in sorted array: "); scanf("%d", &n);
                int arr[n];
                printf("Enter sorted elements: ");
                for(i = 0; i < n; i++) scanf("%d", &arr[i]);
                printf("Enter element to search: "); scanf("%d", &key);
                low = 0; high = n - 1;
                while(low <= high) {
                    mid = (low + high) / 2;
                    if(arr[mid] == key) { pos = mid; break; }
                    else if(arr[mid] < key) low = mid + 1;
                    else high = mid - 1;
                }
                if(pos != -1) printf("Element %d found at position %d\n", key, pos + 1);
                else printf("Element not found\n");
                break;
            }
            case 15: {
                int n, i, j, temp;
                printf("Enter number of elements: "); scanf("%d", &n);
                int arr[n];
                printf("Enter elements: ");
                for(i = 0; i < n; i++) scanf("%d", &arr[i]);
                for(i = 0; i < n - 1; i++) {
                    for(j = 0; j < n - 1 - i; j++) {
                        if(arr[j] > arr[j + 1]) {
                            temp = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = temp;
                        }
                    }
                }
                printf("Sorted array: ");
                for(i = 0; i < n; i++) printf("%d ", arr[i]);
                printf("\n");
                break;
            }
            case 16: {
                int n, val, sum = 0; struct SNode *head = NULL, *temp = NULL;
                printf("Enter number of elements: "); scanf("%d", &n);
                printf("Enter elements: ");
                for(int i = 0; i < n; i++) {
                    scanf("%d", &val);
                    struct SNode* newNode = createSNode(val);
                    if(head == NULL) head = temp = newNode;
                    else { temp->next = newNode; temp = temp->next; }
                }
                temp = head;
                while(temp != NULL) { sum += temp->data; temp = temp->next; }
                printf("Sum of linked list elements = %d\n", sum);
                break;
            }
            case 17: {
                int n, val, key, pos = 1, found = 0; struct SNode *head = NULL, *temp = NULL;
                printf("Enter number of elements: "); scanf("%d", &n);
                printf("Enter elements: ");
                for(int i = 0; i < n; i++) {
                    scanf("%d", &val);
                    struct SNode* newNode = createSNode(val);
                    if(head == NULL) head = temp = newNode;
                    else { temp->next = newNode; temp = temp->next; }
                }
                printf("Enter element to search: "); scanf("%d", &key);
                temp = head;
                while(temp != NULL) {
                    if(temp->data == key) { printf("Element %d found at position %d\n", key, pos); found = 1; }
                    temp = temp->next; pos++;
                }
                if(!found) printf("Element not found\n");
                break;
            }
            case 18: {
                int n, val; struct SNode *head = NULL, *temp = NULL;
                printf("Enter number of elements: "); scanf("%d", &n);
                printf("Enter elements: ");
                for(int i = 0; i < n; i++) {
                    scanf("%d", &val);
                    struct SNode* newNode = createSNode(val);
                    if(head == NULL) head = temp = newNode;
                    else { temp->next = newNode; temp = temp->next; }
                }
                printf("Original list: "); displaySLL(head);
                printf("Enter element to insert at beginning: "); scanf("%d", &val);
                struct SNode* newNode = createSNode(val);
                newNode->next = head; head = newNode;
                printf("List after insertion: "); displaySLL(head);
                break;
            }
            case 19: {
                int n, val; struct SNode *head = NULL, *temp = NULL;
                printf("Enter number of elements: "); scanf("%d", &n);
                printf("Enter elements: ");
                for(int i = 0; i < n; i++) {
                    scanf("%d", &val);
                    struct SNode* newNode = createSNode(val);
                    if(head == NULL) head = temp = newNode;
                    else { temp->next = newNode; temp = temp->next; }
                }
                printf("Original list: "); displaySLL(head);
                printf("Enter element to insert at end: "); scanf("%d", &val);
                struct SNode* newNode = createSNode(val);
                if(head == NULL) head = newNode;
                else {
                    temp = head;
                    while(temp->next != NULL) temp = temp->next;
                    temp->next = newNode;
                }
                printf("List after insertion: "); displaySLL(head);
                break;
            }
            case 20: {
                int n, val, pos; struct SNode *head = NULL, *temp = NULL;
                printf("Enter number of elements: "); scanf("%d", &n);
                printf("Enter elements: ");
                for(int i = 0; i < n; i++) {
                    scanf("%d", &val);
                    struct SNode* newNode = createSNode(val);
                    if(head == NULL) head = temp = newNode;
                    else { temp->next = newNode; temp = temp->next; }
                }
                printf("Original list: "); displaySLL(head);
                printf("Enter position after which to insert: "); scanf("%d", &pos);
                printf("Enter value to insert: "); scanf("%d", &val);
                temp = head;
                for(int i = 1; i < pos && temp != NULL; i++) temp = temp->next;
                if(temp == NULL) printf("Invalid position\n");
                else {
                    struct SNode* newNode = createSNode(val);
                    newNode->next = temp->next; temp->next = newNode;
                    printf("List after insertion: "); displaySLL(head);
                }
                break;
            }
            case 21: {
                int n, val, key; struct SNode *head = NULL, *temp = NULL;
                printf("Enter number of elements: "); scanf("%d", &n);
                printf("Enter elements: ");
                for(int i = 0; i < n; i++) {
                    scanf("%d", &val);
                    struct SNode* newNode = createSNode(val);
                    if(head == NULL) head = temp = newNode;
                    else { temp->next = newNode; temp = temp->next; }
                }
                printf("Original list: "); displaySLL(head);
                printf("Enter element after which to insert: "); scanf("%d", &key);
                printf("Enter value to insert: "); scanf("%d", &val);
                temp = head;
                while(temp != NULL && temp->data != key) temp = temp->next;
                if(temp == NULL) printf("Element not found\n");
                else {
                    struct SNode* newNode = createSNode(val);
                    newNode->next = temp->next; temp->next = newNode;
                    printf("List after insertion: "); displaySLL(head);
                }
                break;
            }
            case 22: {
                int n, val; struct SNode *head = NULL, *temp = NULL;
                printf("Enter number of elements in sorted list: "); scanf("%d", &n);
                printf("Enter sorted elements: ");
                for(int i = 0; i < n; i++) {
                    scanf("%d", &val);
                    struct SNode* newNode = createSNode(val);
                    if(head == NULL) head = temp = newNode;
                    else { temp->next = newNode; temp = temp->next; }
                }
                printf("Original list: "); displaySLL(head);
                printf("Enter value to insert: "); scanf("%d", &val);
                struct SNode* newNode = createSNode(val);
                if(head == NULL || val < head->data) { newNode->next = head; head = newNode; }
                else {
                    temp = head;
                    while(temp->next != NULL && temp->next->data < val) temp = temp->next;
                    newNode->next = temp->next; temp->next = newNode;
                }
                printf("Sorted list after insertion: "); displaySLL(head);
                break;
            }
            case 23: {
                int n, val; struct SNode *head = NULL, *temp = NULL;
                printf("Enter number of elements: "); scanf("%d", &n);
                printf("Enter elements: ");
                for(int i = 0; i < n; i++) {
                    scanf("%d", &val);
                    struct SNode* newNode = createSNode(val);
                    if(head == NULL) head = temp = newNode;
                    else { temp->next = newNode; temp = temp->next; }
                }
                printf("Original list: "); displaySLL(head);
                if(head == NULL) printf("List is empty\n");
                else {
                    temp = head; head = head->next;
                    printf("Deleted node: %d\n", temp->data); free(temp);
                    printf("List after deletion: "); displaySLL(head);
                }
                break;
            }
            case 24: {
                int n, val; struct SNode *head = NULL, *temp = NULL, *prev = NULL;
                printf("Enter number of elements: "); scanf("%d", &n);
                printf("Enter elements: ");
                for(int i = 0; i < n; i++) {
                    scanf("%d", &val);
                    struct SNode* newNode = createSNode(val);
                    if(head == NULL) head = temp = newNode;
                    else { temp->next = newNode; temp = temp->next; }
                }
                printf("Original list: "); displaySLL(head);
                if(head == NULL) printf("List is empty\n");
                else if(head->next == NULL) {
                    printf("Deleted node: %d\n", head->data); free(head); head = NULL;
                } else {
                    temp = head;
                    while(temp->next != NULL) { prev = temp; temp = temp->next; }
                    printf("Deleted node: %d\n", temp->data); prev->next = NULL; free(temp);
                    printf("List after deletion: "); displaySLL(head);
                }
                break;
            }
            case 25: {
                int n, val, key; struct SNode *head = NULL, *temp = NULL, *prev = NULL;
                printf("Enter number of elements: "); scanf("%d", &n);
                printf("Enter elements: ");
                for(int i = 0; i < n; i++) {
                    scanf("%d", &val);
                    struct SNode* newNode = createSNode(val);
                    if(head == NULL) head = temp = newNode;
                    else { temp->next = newNode; temp = temp->next; }
                }
                printf("Original list: "); displaySLL(head);
                printf("Enter element to delete: "); scanf("%d", &key);
                temp = head;
                while(temp != NULL && temp->data != key) { prev = temp; temp = temp->next; }
                if(temp == NULL) printf("Element not found\n");
                else {
                    if(prev == NULL) head = head->next;
                    else prev->next = temp->next;
                    printf("Deleted element: %d\n", temp->data); free(temp);
                    printf("List after deletion: "); displaySLL(head);
                }
                break;
            }
            case 26: {
                int n, val, sum = 0; struct DNode *head = NULL, *temp = NULL;
                printf("Enter number of elements: "); scanf("%d", &n);
                printf("Enter elements: ");
                for(int i = 0; i < n; i++) {
                    scanf("%d", &val);
                    struct DNode* newNode = createDNode(val);
                    if(head == NULL) head = temp = newNode;
                    else { newNode->prev = temp; temp->next = newNode; temp = temp->next; }
                }
                temp = head;
                while(temp != NULL) { sum += temp->data; temp = temp->next; }
                printf("Sum of two-way linked list elements = %d\n", sum);
                break;
            }
            case 27: {
                int n, val, pos; struct DNode *head = NULL, *temp = NULL;
                printf("Enter number of elements: "); scanf("%d", &n);
                printf("Enter elements: ");
                for(int i = 0; i < n; i++) {
                    scanf("%d", &val);
                    struct DNode* newNode = createDNode(val);
                    if(head == NULL) head = temp = newNode;
                    else { newNode->prev = temp; temp->next = newNode; temp = temp->next; }
                }
                printf("Original list: "); displayDLL(head);
                printf("Enter position to insert (1 to %d): ", n + 1); scanf("%d", &pos);
                printf("Enter value to insert: "); scanf("%d", &val);
                struct DNode* newNode = createDNode(val);
                if(pos == 1) {
                    newNode->next = head; if(head != NULL) head->prev = newNode; head = newNode;
                } else {
                    temp = head;
                    for(int i = 1; i < pos - 1 && temp != NULL; i++) temp = temp->next;
                    if(temp != NULL) {
                        newNode->next = temp->next; newNode->prev = temp;
                        if(temp->next != NULL) temp->next->prev = newNode;
                        temp->next = newNode;
                    }
                }
                printf("List after insertion: "); displayDLL(head);
                break;
            }
            case 28: {
                int n, val, key; struct DNode *head = NULL, *temp = NULL;
                printf("Enter number of elements: "); scanf("%d", &n);
                printf("Enter elements: ");
                for(int i = 0; i < n; i++) {
                    scanf("%d", &val);
                    struct DNode* newNode = createDNode(val);
                    if(head == NULL) head = temp = newNode;
                    else { newNode->prev = temp; temp->next = newNode; temp = temp->next; }
                }
                printf("Original list: "); displayDLL(head);
                printf("Enter element to delete: "); scanf("%d", &key);
                temp = head;
                while(temp != NULL && temp->data != key) temp = temp->next;
                if(temp == NULL) printf("Element not found\n");
                else {
                    if(temp->prev != NULL) temp->prev->next = temp->next;
                    else head = temp->next;
                    if(temp->next != NULL) temp->next->prev = temp->prev;
                    printf("Deleted element: %d\n", temp->data); free(temp);
                    printf("List after deletion: "); displayDLL(head);
                }
                break;
            }
            case 29: {
                int c, val;
                while(1) {
                    printf("\n1. Push  2. Pop  3. Display  4. Exit Stack\nEnter choice: ");
                    scanf("%d", &c);
                    if(c == 1) { printf("Enter value: "); scanf("%d", &val); push_arr(val); }
                    else if(c == 2) { val = pop_arr(); if(val != -1) printf("Popped: %d\n", val); }
                    else if(c == 3) {
                        if(top_arr == -1) printf("Stack is empty\n");
                        else { printf("Stack (top to bottom): "); for(int i=top_arr; i>=0; i--) printf("%d ", stack_arr[i]); printf("\n"); }
                    }
                    else break;
                }
                break;
            }
            case 30: {
                int c, val;
                while(1) {
                    printf("\n1. Push  2. Pop  3. Display  4. Exit Stack\nEnter choice: ");
                    scanf("%d", &c);
                    if(c == 1) { printf("Enter value: "); scanf("%d", &val); push_ll(val); }
                    else if(c == 2) { val = pop_ll(); if(val != -1) printf("Popped: %d\n", val); }
                    else if(c == 3) {
                        if(top_ll == NULL) printf("Stack is empty\n");
                        else { printf("Stack (top to bottom): "); struct SNode *t = top_ll; while(t){ printf("%d ", t->data); t = t->next; } printf("\n"); }
                    }
                    else break;
                }
                break;
            }
            case 31: {
                char infix[MAX], postfix[MAX], p_stack[MAX];
                int i, j = 0, len, p_top = -1;
                printf("Enter infix expression: "); scanf("%s", infix);
                len = strlen(infix);
                for(i = 0; i < len; i++) {
                    char c = infix[i];
                    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) postfix[j++] = c;
                    else if(c == '(') p_stack[++p_top] = c;
                    else if(c == ')') {
                        while(p_top != -1 && p_stack[p_top] != '(') postfix[j++] = p_stack[p_top--];
                        if(p_top != -1) p_top--; // pop '('
                    } else if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
                        int prec_c = (c=='^') ? 3 : ((c=='*' || c=='/') ? 2 : 1);
                        while(p_top != -1) {
                            char top_c = p_stack[p_top];
                            int prec_t = (top_c=='^') ? 3 : ((top_c=='*' || top_c=='/') ? 2 : ((top_c=='+' || top_c=='-') ? 1 : 0));
                            if(prec_t >= prec_c) postfix[j++] = p_stack[p_top--];
                            else break;
                        }
                        p_stack[++p_top] = c;
                    }
                }
                while(p_top != -1) postfix[j++] = p_stack[p_top--];
                postfix[j] = '\0';
                printf("Postfix expression: %s\n", postfix);
                break;
            }
            case 32: {
                int c, val;
                while(1) {
                    printf("\n1. Enqueue  2. Dequeue  3. Display  4. Exit Queue\nEnter choice: ");
                    scanf("%d", &c);
                    if(c == 1) { printf("Enter value: "); scanf("%d", &val); enqueue_arr(val); }
                    else if(c == 2) { val = dequeue_arr(); if(val != -1) printf("Dequeued: %d\n", val); }
                    else if(c == 3) {
                        if(front_arr == -1 || front_arr > rear_arr) printf("Queue is empty\n");
                        else { printf("Queue (front to rear): "); for(int i=front_arr; i<=rear_arr; i++) printf("%d ", queue_arr[i]); printf("\n"); }
                    }
                    else break;
                }
                break;
            }
            case 33: {
                int c, val;
                while(1) {
                    printf("\n1. Enqueue  2. Dequeue  3. Display  4. Exit Queue\nEnter choice: ");
                    scanf("%d", &c);
                    if(c == 1) { printf("Enter value: "); scanf("%d", &val); enqueue_ll(val); }
                    else if(c == 2) { val = dequeue_ll(); if(val != -1) printf("Dequeued: %d\n", val); }
                    else if(c == 3) {
                        if(front_ll == NULL) printf("Queue is empty\n");
                        else { printf("Queue (front to rear): "); struct SNode *t = front_ll; while(t){ printf("%d ", t->data); t = t->next; } printf("\n"); }
                    }
                    else break;
                }
                break;
            }
            case 34: {
                int n, i;
                printf("Enter number of elements: "); scanf("%d", &n);
                int arr[n];
                printf("Enter elements: ");
                for(i = 0; i < n; i++) scanf("%d", &arr[i]);
                qSort(arr, 0, n - 1);
                printf("Sorted array: ");
                for(i = 0; i < n; i++) printf("%d ", arr[i]);
                printf("\n");
                break;
            }
            case 35: {
                int n, val, key; struct TNode *root = NULL;
                printf("Enter number of elements: "); scanf("%d", &n);
                printf("Enter elements: ");
                for(int i = 0; i < n; i++) { scanf("%d", &val); root = insertBST(root, val); }
                printf("BST Inorder Traversal: "); inorderBST(root); printf("\n");
                printf("Enter element to search: "); scanf("%d", &key);
                if(searchBST(root, key)) printf("%d found in BST\n", key);
                else printf("%d not found in BST\n", key);
                break;
            }
            case 36: {
                int n, val; struct TNode *root = NULL;
                printf("Enter number of elements: "); scanf("%d", &n);
                printf("Enter elements: ");
                for(int i = 0; i < n; i++) { scanf("%d", &val); root = insertBST(root, val); }
                printf("Pre-order Traversal:  "); preorderBST(root);
                printf("\nIn-order Traversal:   "); inorderBST(root);
                printf("\nPost-order Traversal: "); postorderBST(root); printf("\n");
                break;
            }
            case 37: {
                int edges, u, v, i, j;
                printf("Enter number of vertices: "); scanf("%d", &vertices);
                printf("Enter number of edges: "); scanf("%d", &edges);
                for(i = 0; i < vertices; i++) for(j = 0; j < vertices; j++) graph[i][j] = 0;
                printf("Enter edges (u v):\n");
                for(i = 0; i < edges; i++) { scanf("%d %d", &u, &v); addEdge(u, v); }
                printf("Adjacency Matrix:\n  ");
                for(i = 0; i < vertices; i++) printf("%d ", i);
                printf("\n");
                for(i = 0; i < vertices; i++) {
                    printf("%d ", i);
                    for(j = 0; j < vertices; j++) printf("%d ", graph[i][j]);
                    printf("\n");
                }
                break;
            }
            case 38: {
                int n, i, j, key;
                printf("Enter number of elements: "); scanf("%d", &n);
                int arr[n];
                printf("Enter elements: ");
                for(i = 0; i < n; i++) scanf("%d", &arr[i]);
                for(i = 1; i < n; i++) {
                    key = arr[i]; j = i - 1;
                    while(j >= 0 && arr[j] > key) { arr[j + 1] = arr[j]; j--; }
                    arr[j + 1] = key;
                }
                printf("Sorted array: ");
                for(i = 0; i < n; i++) printf("%d ", arr[i]);
                printf("\n");
                break;
            }
            case 39: {
                int n, i, j, minIdx, temp;
                printf("Enter number of elements: "); scanf("%d", &n);
                int arr[n];
                printf("Enter elements: ");
                for(i = 0; i < n; i++) scanf("%d", &arr[i]);
                for(i = 0; i < n - 1; i++) {
                    minIdx = i;
                    for(j = i + 1; j < n; j++) { if(arr[j] < arr[minIdx]) minIdx = j; }
                    temp = arr[minIdx]; arr[minIdx] = arr[i]; arr[i] = temp;
                }
                printf("Sorted array: ");
                for(i = 0; i < n; i++) printf("%d ", arr[i]);
                printf("\n");
                break;
            }
            case 40: {
                int n, i;
                printf("Enter number of elements: "); scanf("%d", &n);
                int arr[n];
                printf("Enter elements: ");
                for(i = 0; i < n; i++) scanf("%d", &arr[i]);
                m_sort(arr, 0, n - 1);
                printf("Sorted array: ");
                for(i = 0; i < n; i++) printf("%d ", arr[i]);
                printf("\n");
                break;
            }
            default:
                printf("Invalid choice! Please select between 0 and 40.\n");
        }
    }
    return 0;
}