#include <stdio.h>
#include <time.h>

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    int n, i;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    start = clock();
    for (i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nExecution time: %f seconds\n", cpu_time_used);

    return 0;
}