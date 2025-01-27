#include <stdio.h>

// Function to swap two integers using pointers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to increment a value using a pointer
void increment(int *num) {
    (*num)++;
}

// Function to print an array using a pointer
void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

// Function to reverse an array using pointers
void reverse_array(int *arr, int size) {
    int *start = arr;
    int *end = arr + size - 1;
    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main() {
    int x = 10, y = 20;
    printf("Before swap: x = %d, y = %d\n", x, y);

    // Swap two integers using pointers
    swap(&x, &y);
    printf("After swap: x = %d, y = %d\n\n", x, y);

    // Increment a value using a pointer
    increment(&x);
    printf("After incrementing x: x = %d\n\n", x);

    // Array operations with pointers
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    print_array(arr, size);

    reverse_array(arr, size);

    printf("Reversed array: ");
    print_array(arr, size);

    return 0;
}
