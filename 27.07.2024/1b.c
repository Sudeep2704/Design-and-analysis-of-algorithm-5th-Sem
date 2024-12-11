// Write a c program to convert the first n decimal numbers into binary.Read all pair of numbers form a file input taken from file.Store the result in a seperate file.

#include <stdio.h>

void decimalToBinary(int n, char *binary)
{
    int index = 0;
    if (n == 0)
    {
        binary[index++] = '0';
    }
    else
    {
        while (n > 0)
        {
            binary[index++] = (n % 2) + '0';
            n /= 2;
        }
    }
    binary[index] = '\0';

    int len = index;
    for (int i = 0; i < len / 2; i++)
    {
        char temp = binary[i];
        binary[i] = binary[len - i - 1];
        binary[len - i - 1] = temp;
    }
}

int main()
{
    FILE *inputFile, *outputFile;
    int n, num;

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL)
    {
        printf("Error opening input file.\n");
        return 1;
    }

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL)
    {
        printf("Error opening output file.\n");
        fclose(inputFile);
        return 1;
    }

    while (fscanf(inputFile, "%d", &n) != EOF)
    {
        for (num = 0; num < n; num++)
        {
            char binary[33];
            decimalToBinary(num, binary);
            fprintf(outputFile, "%d: %s\n", num, binary);
        }
        fprintf(outputFile, "\n");
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Binary conversions have been written to output.txt\n");
    return 0;
}












