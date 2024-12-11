#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L and R
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
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

            mergeSort(arr, 0, n - 1);

            outAsce = fopen("outMergeAsce.dat", "w");
            if (outAsce == NULL) {
                printf("Error opening output file.\n");
                return 1;
            }

            for (int i = 0; i < n; i++) {
                fprintf(outAsce, "%d\n", arr[i]);
            }

            fclose(outAsce);

            printf("Sorted numbers have been written to outMergeAsce.dat \n");

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

            mergeSort(arr, 0, n - 1);

            outDesc = fopen("outMergeDesc.dat", "w");
            if (outDesc == NULL) {
                printf("Error opening output file.\n");
                return 1;
            }

            for (int i = 0; i < n; i++) {
                fprintf(outDesc, "%d\n", arr[i]);
            }

            fclose(outDesc);

            printf("Sorted numbers have been written to outMergeDesc.dat \n");
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

            mergeSort(arr, 0, n - 1);

            outRand = fopen("outMergeRand.dat", "w");
            if (outRand == NULL) {
                printf("Error opening output file.\n");
                return 1;
            }

            for (int i = 0; i < n; i++) {
                fprintf(outRand, "%d\n", arr[i]);
            }

            fclose(outRand);

            printf("Sorted numbers have been written to outMergeRand.dat \n");
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
