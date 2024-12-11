#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // pivot
    int i = (low - 1);     // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[pi] is now at right place
        int pi = partition(arr, low, high);

        // Separately sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int main() {

int input;
    int arr[1000], n = 0;
    FILE *inputfileAsen;
    FILE *outAsce;
    FILE *inputfileDesc;
    FILE *outDesc;
    FILE *inputfileRand;
    FILE *outRand;
    clock_t start, end;
    double cpu_time_used;

    printf("Menu Driven Merge Sort\n");
    printf("_____________________________\n");

    printf("1. Ascending Data \n");
    printf("2. Descending Data \n");
    printf("3. Random Data\n");
    printf("4. Exit program\n");

    printf("Enter the option you prefer\n");
    scanf("%d", &input);

    switch (input) {
        case 1:
        start = clock();
            inputfileAsen = fopen("inAsce.dat", "r");
            if (inputfileAsen == NULL) {
                printf("Error opening input file.\n");
                return 1;
            }

            while (fscanf(inputfileAsen, "%d", &arr[n]) != EOF) {
                n++;
            }
            fclose(inputfileAsen);

            quickSort(arr, 0, n - 1);

            outAsce = fopen("outQuickAsce.dat", "w");
            if (outAsce == NULL) {
                printf("Error opening output file.\n");
                return 1;
            }

            for (int i = 0; i < n; i++) {
                fprintf(outAsce, "%d\n", arr[i]);
            }

            fclose(outAsce);

            printf("Sorted numbers have been written to outQuickAsce.dat \n");

            end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Time taken: %f seconds\n", cpu_time_used);
            break;

        case 2:
        start = clock();
            inputfileDesc = fopen("inDesc.dat", "r");
            if (inputfileDesc == NULL) {
                printf("Error opening input file.\n");
                return 1;
            }

            while (fscanf(inputfileDesc, "%d", &arr[n]) != EOF) {
                n++;
            }
            fclose(inputfileDesc);

            quickSort(arr, 0, n - 1);

            outDesc = fopen("outQuickDesc.dat", "w");
            if (outDesc == NULL) {
                printf("Error opening output file.\n");
                return 1;
            }

            for (int i = 0; i < n; i++) {
                fprintf(outDesc, "%d\n", arr[i]);
            }

            fclose(outDesc);

            printf("Sorted numbers have been written to outQuickDesc.dat \n");
end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Time taken: %f seconds\n", cpu_time_used);



            break;


        case 3:
        start = clock();
            inputfileRand = fopen("inRand.dat", "r");
            if (inputfileRand == NULL) {
                printf("Error opening input file.\n");
                return 1;
            }

            while (fscanf(inputfileRand, "%d", &arr[n]) != EOF) {
                n++;
            }
            fclose(inputfileRand);

            quickSort(arr, 0, n - 1);

            outRand = fopen("outQuickRand.dat", "w");
            if (outRand == NULL) {
                printf("Error opening output file.\n");
                return 1;
            }

            for (int i = 0; i < n; i++) {
                fprintf(outRand, "%d\n", arr[i]);
            }

            fclose(outRand);

            printf("Sorted numbers have been written to outQuickRand.dat \n");
            end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Time taken: %f seconds\n", cpu_time_used);
            break;

        case 4:
            exit(0);

        default:
            printf("\nInvalid choice\n");
            break;
    }

    return 0;
}





