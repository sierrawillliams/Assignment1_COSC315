#include <stdio.h>
#include <stdlib.h>

int main() {
    // 1. Get the number of inputs from the user
    int num, i, count, min=0, max=0, sum=0;
    float avg;
    printf("How many numbers you wish to use: ");
    scanf("%d", &count);
    
    // 2. Read the number of inputs from the user
    // You will need to use an array to handle all of the inputs.
    // Basic array can be defined as such: int a[int_length]
    for (i = 0; i < count; i++){
        printf("Enter %d numbers separated by spaces: ", count);
        scanf("%d", &num);
    
    // 3. Calculate the min, max, sum and average
    // Make sure to cast ints to floats for proper decimal output
    if (i == 0){
        min = num;
        max = num;
    } else {
        if (num < min){
            min = num;
        }
        if (num > max){
            max = num;
        }
    }
    sum += num;
    }
    avg = (float)sum /count;
    printf("Min: %d, Max: %d, Sum: %d, Avg: %.2f\n", min, max, sum, avg);
    // 4. Correctly print the stats
    return 0;
}
