#Factorial Recursivo

import time
import tracemalloc
import matplotlib.pyplot as plt

def facto_r(n):
    if n < 0:
        return "Error"
    elif n == 0 or n == 1:
        return 1
    else:
        return n * facto_r(n - 1)

def medir_rendimiento(func, n):
    tracemalloc.start()
    start = time.perf_counter()
    resultado = func(n)
    end = time.perf_counter()
    memoria_actual, pico_memoria = tracemalloc.get_traced_memory()
    tracemalloc.stop()
    tiempo = end - start
    return resultado, tiempo, pico_memoria / 1024  # en KB

valores_n = list(range(1, 501))
tiempos = []
memorias = []

for n in valores_n:
    _, tiempo, memoria = medir_rendimiento(facto_r, n)
    tiempos.append(tiempo)
    memorias.append(memoria)

# Mostrar resultado de ejemplo
print("Factorial recursivo de 5:", facto_r(5))

# Gráfica de tiempo
plt.figure()
plt.plot(valores_n, tiempos, label="Tiempo (seg)")
plt.title("Recursivo: n vs tiempo")
plt.xlabel("n")
plt.ylabel("Tiempo (s)")
plt.grid(True)
plt.legend()
plt.show()

# Gráfica de memoria
plt.figure()
plt.plot(valores_n, memorias, label="Memoria (KB)", color="orange")
plt.title("Recursivo: n vs memoria")
plt.xlabel("n")
plt.ylabel("Memoria pico (KB)")
plt.grid(True)
plt.legend()
plt.show()