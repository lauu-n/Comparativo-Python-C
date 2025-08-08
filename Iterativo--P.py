# Factorial Iterativo

import time
import tracemalloc
import matplotlib.pyplot as plt

def fact_i(n):
    if n < 0:
        return "Error"
    result = 1
    for i in range(1, n + 1):
        result *= i
    return result

def medir_rendimiento(func, n):
    tracemalloc.start()
    start = time.perf_counter()
    resultado = func(n)
    end = time.perf_counter()
    memoria_actual, pico_memoria = tracemalloc.get_traced_memory()
    tracemalloc.stop()
    tiempo = end - start
    return resultado, tiempo, pico_memoria / 1024  # en KB

valores_n = list(range(1, 1001))
tiempos = []
memorias = []

for n in valores_n:
    _, tiempo, memoria = medir_rendimiento(fact_i, n)
    tiempos.append(tiempo)
    memorias.append(memoria)

# Mostrar resultado de ejemplo
print("Factorial iterativo de 5:", fact_i(5))

# Gráfica de tiempo
plt.figure()
plt.plot(valores_n, tiempos, label="Tiempo (seg)")
plt.title("Iterativo: n vs tiempo")
plt.xlabel("n")
plt.ylabel("Tiempo (s)")
plt.grid(True)
plt.legend()
plt.show()

# Gráfica de memoria
plt.figure()
plt.plot(valores_n, memorias, label="Memoria (KB)", color="green")
plt.title("Iterativo: n vs memoria")
plt.xlabel("n")
plt.ylabel("Memoria pico (KB)")
plt.grid(True)
plt.legend()
plt.show()
