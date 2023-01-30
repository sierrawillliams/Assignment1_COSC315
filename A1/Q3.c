#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int count, i;
    int range_start = 40;
    int range_end = 100;
    printf("Generating numbers from %d to %d\n", range_start, range_end);

    // 1. Get the number of ints to generate from the user
    int num;
    printf("Enter how many numbers you wish to generate: ");
    scanf("%d", &count);
    srand(time(NULL));
    // 2. Malloc an int array and fill with random numbers
    // Randomly generated numbers should fall within the defined range
    double* A = (double*) malloc(num * sizeof(double));
    if (A == NULL) {
        printf("Error allocating memory!\n");
        return 1;
    }
    for (i = 0; i < count; i++){
        A[i] = (rand() % (range_end - range_start+1)) + range_start;
    }
    // 3. Print generated numbers
    printf("Generated Numbers: ", A);
    for (i=0; i < count; i++){
        printf("%d ", A[i]);
    }
    
    // 4. Malloc a char array and fill by casting numbers from the int array
    char* B = (char*) malloc(sizeof(char)*(sizeof(double)+1));
    if(B == NULL){
        printf("Error allocating memory!\n");
        return 1;
    }

    for (i = 0; i < count; i++){
        B[i] = (char)A[i];
    }
    // 5. Print the random letters (HINT: use %s)
    printf("Random letters: ", B);
    for (i = 0; i < count; i++){
        printf("%c ", B[i]);
    }
    printf("\n");
    free(A);
    free(B);
    return 0;
}