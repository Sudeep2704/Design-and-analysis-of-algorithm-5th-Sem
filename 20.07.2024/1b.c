#include <stdio.h>

void calculatePrefixSum(int arr[], int prefixSum[], int n) {
    prefixSum[0] = arr[0];  // The first element of prefix sum is the same as the first element of the array

    // Calculate prefix sum for the rest of the elements
    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }
}

int main() {
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n], prefixSum[n];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    calculatePrefixSum(arr, prefixSum, n);

    printf("Prefix sum array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", prefixSum[i]);
    }

    return 0;
}