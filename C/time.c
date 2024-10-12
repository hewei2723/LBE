#include <stdio.h>
#include <time.h>

int main()
{
    clock_t start = clock();
    // your code here
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time spent: %f seconds\n", time_spent);

        
}