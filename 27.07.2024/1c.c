// Write a c program to sort n numbers of elements from the file using insertion sort and the sorted array is stored into a seperate file.

#include <stdio.h>

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    FILE *inputFile, *outputFile;
    int arr[1000], n = 0;

    inputFile = fopen("2c.txt", "r");
    if (inputFile == NULL)
    {
        printf("Error opening input file.\n");
        return 1;
    }

    while (fscanf(inputFile, "%d", &arr[n]) != EOF)
    {
        n++;
    }

    fclose(inputFile);

    insertionSort(arr, n);

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL)
    {
        printf("Error opening output file.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        fprintf(outputFile, "%d\n", arr[i]);
    }

    fclose(outputFile);

    printf("Sorted numbers have been written to output.txt\n");
    return 0;
}