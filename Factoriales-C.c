#include <stdio.h>
#include <time.h>
#include <sys/resource.h> // Para medir uso de memoria

// Función recursiva factorial
unsigned long long facto_r(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * facto_r(n - 1);
}

// Función iterativa factorial
unsigned long long facto_i(int n) {
    unsigned long long resultado = 1;
    for (int i = 1; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

// Función para obtener memoria usada en KB
long get_memory_usage_kb() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    return usage.ru_maxrss; // Retorna KB
}

int main() {
    int n;
    printf("Ingrese un numero para calcular su factorial: ");
    scanf("%d", &n);

    // --- FACTORIAL RECURSIVO ---
    clock_t start_r = clock();
    unsigned long long res_r = facto_r(n);
    clock_t end_r = clock();

    long mem_r = get_memory_usage_kb();
    double time_r = (double)(end_r - start_r) / CLOCKS_PER_SEC;

    printf("\n[Factorial Recursivo]");
    printf("\nValor: %llu", res_r);
    printf("\nTiempo de ejecucion: %f segundos", time_r);
    printf("\nMemoria usada: %ld KB\n", mem_r);

    // --- FACTORIAL ITERATIVO ---
    clock_t start_i = clock();
    unsigned long long res_i = facto_i(n);
    clock_t end_i = clock();

    long mem_i = get_memory_usage_kb();
    double time_i = (double)(end_i - start_i) / CLOCKS_PER_SEC;

    printf("\n[Factorial Iterativo]");
    printf("\nValor: %llu", res_i);
    printf("\nTiempo de ejecucion: %f segundos", time_i);
    printf("\nMemoria usada: %ld KB\n", mem_i);

    return 0;
}
