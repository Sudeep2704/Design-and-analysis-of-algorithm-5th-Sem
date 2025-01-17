#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 100

int main() {
    FILE *fptr;
    int array[MAX_SIZE];
    int i = 0;

    fptr = fopen("1a.txt", "r");
    if (fptr == NULL) {
        printf("Error opening file.\n");
        return 1;
    }


    while (fscanf(fptr, "%d", &array[i]) != EOF && i < MAX_SIZE) {
        i++;
    }

    
    

    if (i < 2) {
        printf("Not enough integers in the file to find second smallest and second largest.\n");
        return 1;
    }

    int smallest = INT_MAX;
    int second_smallest = INT_MAX;
    int largest = INT_MIN;
    int second_largest = INT_MIN;

   
    for (int j = 0; j < i; j++) {
        if (array[j] < smallest) {
            second_smallest = smallest;
            smallest = array[j];
        } else if (array[j] < second_smallest && array[j] != smallest) {
            second_smallest = array[j];
        }

        if (array[j] > largest) {
            second_largest = largest;
            largest = array[j];
        } else if (array[j] > second_largest && array[j] != largest) {
            second_largest = array[j];
        }
    }

    
    printf("Read integers:\n");
    for (int j = 0; j < i; j++) {
        printf("%d\n", array[j]);
    }

    
    printf("Smallest number: %d and Second smallest number: %d\n", smallest, second_smallest);
  
    printf("Largest number: %d and Second largest number: %d\n", largest, second_largest);
   

    return 0;
}
