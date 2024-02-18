#include <stdio.h>
#include <time.h>

int fibonacci(int n) {
    int fib[n+1];
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    return fib[n];
}
int main() {
    int n;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    start = clock();
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nExecution time: %f seconds\n", cpu_time_used);

    return 0;
}