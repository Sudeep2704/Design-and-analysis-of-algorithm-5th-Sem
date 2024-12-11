#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int a, b;
    FILE *ftr, *otr;
    clock_t start, end;
    double cpu_time_used;

    
    start = clock();

   
    ftr = fopen("input.txt", "r");
    if (ftr == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    
    if (fscanf(ftr, "%d %d", &a, &b) != 2) {
        perror("Error reading numbers from input file");
        fclose(ftr);
        exit(EXIT_FAILURE);
    }
    fclose(ftr);

   
    int result = gcd(a, b);

    
    otr = fopen("output.txt", "w");
    if (otr == NULL) {
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    
    fprintf(otr, "GCD of %d and %d is %d\n", a, b, result);
    fclose(otr);    
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Time taken: %f seconds\n", cpu_time_used);

    return 0;
}
