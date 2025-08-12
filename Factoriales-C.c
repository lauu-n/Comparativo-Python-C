#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Factorial iterativo
unsigned long long fact_i(int n) {
    if (n < 0) return 0;
    unsigned long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Factorial recursivo
unsigned long long fact_r(int n) {
    if (n < 0) return 0;
    if (n == 0 || n == 1) return 1;
    return n * fact_r(n - 1);
}

// Medir tiempo en segundos
double medir_tiempo(unsigned long long (*func)(int), int n) {
    clock_t start = clock();
    func(n);
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}

// Estimación de memoria (aproximada)
size_t memoria_iterativa(int n) {
    // Memoria de variables locales y acumulador
    return sizeof(unsigned long long) + sizeof(int);
}

size_t memoria_recursiva(int n) {
    // Cada llamada agrega variables locales y el return address
    return (sizeof(unsigned long long) + sizeof(int) + sizeof(void *)) * n;
}

int main() {
    int valores_n[] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000};
    int num_valores = sizeof(valores_n) / sizeof(valores_n[0]);

    printf("n\tIterativo (s)\tMem KB\tRecursivo (s)\tMem KB\n");
    printf("--------------------------------------------------------\n");

    for (int i = 0; i < num_valores; i++) {
        int n = valores_n[i];

        double tiempo_i = medir_tiempo(fact_i, n);
        double tiempo_r = medir_tiempo(fact_r, n);

        double mem_i = memoria_iterativa(n) / 1024.0;
        double mem_r = memoria_recursiva(n) / 1024.0;

        printf("%d\t%.8f\t%.4f\t%.8f\t%.4f\n", n, tiempo_i, mem_i, tiempo_r, mem_r);
    }

    return 0;
}