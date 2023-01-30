#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>
#include <errno.h>
#include <string.h>

#define MAX_LENGTH 100

int main(int argc, char *argv[]) {
    // argv[1] gets us the path passed as an argument to
    // our executed program.
    char *filename = argv[1];
    int nums_to_read, fd, i, j;
    char buffer[MAX_LENGTH];
    char number[MAX_LENGTH];
    int isNumber = 1;

    fd = open(argv[1], O_RDONLY);
    // 1. Get how many numbers we want to read
    printf("How many numbers do you want to read: ");
    scanf("%d", &nums_to_read);

    
    // 2. Attempt to get the file descriptor for our file
    // HINT: Make sure to properly error check the output
    // from the system call.
    printf("Getting a file descriptor for %s\n", filename);

    // 3. Attempt to read the file's contents
    // HINT: A calloc-made char array can be used as a buffer
    //      An example for a float array follows:
    //      float *a = (float *) calloc(num_of_floats, sizeof(float));
    // HINT: Make sure to properly error check the output from the
    // system call.
    
    printf("Reading up to %d numbers from the file\n", nums_to_read);

    // 4. Check that the read content is an integer
    for (i = 0; i < nums_to_read; i++){
        if(buffer[i] < '0' || buffer[i] > '9'){
            isNumber = 0;
            break;
        }
    }
    if (isNumber) {
        for (i = 0; i < nums_to_read; i++){
            number[i] = buffer[i];
        }
    printf("Reversed: ");
    for (i = nums_to_read - 1; i >=0; i--){
        printf("%c", number[i]);
    }
    printf("\n");
    } else {
        printf("No valid number. \n");
    }
    // 5. Reverse and print the file content, if it is a number

    // 6. Free memory from calloc and close open file descriptors
    if(close(fd) == -1){
        printf("Error closing file: %s\n", strerror(errno));
        return 1;
    }
    return 0;
}