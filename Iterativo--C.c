#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

// Función iterativa para calcular factorial
unsigned long long factorial_iterativo(int n) {
    unsigned long long resultado = 1;
    for (int i = 1; i <= n; ++i)
        resultado *= i;
    return resultado;
}

// Función para obtener memoria residente (Linux)
double obtener_memoria_MB() {
    long rss = 0;
    FILE* fp = fopen("/proc/self/statm", "r");
    if (fp == NULL) return 0.0;
    if (fscanf(fp, "%*s %ld", &rss) != 1) {
        fclose(fp);
        return 0.0;
    }
    fclose(fp);
    long page_size = sysconf(_SC_PAGESIZE);
    return (rss * page_size) / (1024.0 * 1024.0);
}

// Función para calcular diferencia de tiempo en segundos
double tiempo_transcurrido(struct timespec inicio, struct timespec fin) {
    return (fin.tv_sec - inicio.tv_sec) + 
           (fin.tv_nsec - inicio.tv_nsec) / 1e9;
}

int main() {
    printf("n   n!                  Tiempo (s)       Memoria (MB)\n");
    printf("--  -------------------  --------------   -------------\n");
    
    for (int i = 1; i <= 20; i++) {
        // Medir memoria antes
        double mem_antes = obtener_memoria_MB();

        // Medir tiempo con alta resolución
        struct timespec start, end;
        clock_gettime(CLOCK_MONOTONIC, &start);
        
        unsigned long long fact = factorial_iterativo(i);
        
        clock_gettime(CLOCK_MONOTONIC, &end);
        double tiempo = tiempo_transcurrido(start, end);

        // Medir memoria después
        double mem_despues = obtener_memoria_MB();
        double mem_uso = mem_despues - mem_antes;
        
        // Mostrar resultados
        printf("%-2d  %-19llu  %-15.10f   %.6f\n", i, fact, tiempo, mem_uso);
    }
    
    return 0;
}