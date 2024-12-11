#include <stdio.h>

#define MAX_SIZE 1000  // Maximum size of the array

// Function to remove duplicates from the array
int removeDuplicates(int arr[], int n) {
    if (n == 0 || n == 1)
        return n;

    int temp[MAX_SIZE];
    int j = 0;

    // Copy unique elements to temp array
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != arr[i + 1]) {
            temp[j++] = arr[i];
        }
    }
    temp[j++] = arr[n - 1];  // Copy the last element

    // Modify the original array
    for (int i = 0; i < j; i++) {
        arr[i] = temp[i];
    }

    return j;  // Return the new size of the array
}

int main() {
    int arr[MAX_SIZE];
    int n = 0;
    FILE *file;

    // Open the file for reading
    file = fopen("numbers.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Read integers from the file and store them in the array
    while (fscanf(file, "%d", &arr[n]) != EOF) {
        n++;
        if (n >= MAX_SIZE) {
            printf("Array size exceeded.\n");
            break;
        }
    }

    fclose(file);

    // Print the original array
    printf("Original array (with duplicates):\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sort the array to easily remove duplicates
    // You can use any sorting algorithm. Here, I am using bubble sort for simplicity.
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Remove duplicates from the array
    n = removeDuplicates(arr, n);

    // Print the array after removing duplicates
    printf("Array after removing duplicates:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}