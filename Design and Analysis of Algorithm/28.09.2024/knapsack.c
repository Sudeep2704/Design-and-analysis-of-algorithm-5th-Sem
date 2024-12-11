#include <stdio.h>

// Structure for items
struct ITEM {
    int item_id;
    int item_profit;
    int item_weight;
    float profit_weight_ratio;
};

// Function to swap two items
void swap(struct ITEM* a, struct ITEM* b) {
    struct ITEM temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree rooted at node i
void heapify(struct ITEM arr[], int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // left child
    int right = 2 * i + 2; // right child

    // Check if left child is larger than root
    if (left < n && arr[left].profit_weight_ratio > arr[largest].profit_weight_ratio)
        largest = left;

    // Check if right child is larger than largest so far
    if (right < n && arr[right].profit_weight_ratio > arr[largest].profit_weight_ratio)
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Function to perform heap sort
void heapSort(struct ITEM arr[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(&arr[0], &arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Function to calculate maximum profit using Fractional Knapsack
float fractionalKnapsack(struct ITEM items[], int n, int capacity) {
    // Sort items by profit/weight ratio using heap sort
    heapSort(items, n);

    float maxProfit = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {
        // If adding the item doesn't exceed capacity, take it fully
        if (currentWeight + items[i].item_weight <= capacity) {
            currentWeight += items[i].item_weight;
            maxProfit += items[i].item_profit;
        }
        // Otherwise, take the fractional part of the item
        else {
            int remainingCapacity = capacity - currentWeight;
            maxProfit += items[i].profit_weight_ratio * remainingCapacity;
            break; // Knapsack is full
        }
    }

    return maxProfit;
}

int main() {
    int n, capacity;

    // Input number of items
    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct ITEM items[n];

    // Input profit and weight of each item
    for (int i = 0; i < n; i++) {
        printf("Enter the profit and weight of item no %d: ", i + 1);
        scanf("%d %d", &items[i].item_profit, &items[i].item_weight);
        items[i].item_id = i + 1;
        items[i].profit_weight_ratio = (float)items[i].item_profit / items[i].item_weight;
    }

    // Input knapsack capacity
    printf("Enter the capacity of knapsack: ");
    scanf("%d", &capacity);

    // Calculate the maximum profit
    float maxProfit = fractionalKnapsack(items, n, capacity);

    // Output the result
    printf("Maximum profit: %.2f\n", maxProfit);

    return 0;
}
