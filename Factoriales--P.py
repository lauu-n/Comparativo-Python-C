import time
import tracemalloc
import matplotlib.pyplot as plt

#Factorial iterativo
def fact_i(n):
    if n < 0:
        return "Error"
    result = 1
    for i in range(1, n + 1):
        result *= i
    return result

#Factorial recursivo
def fact_r(n):
    if n < 0:
        return "Error"
    elif n == 0 or n == 1:
        return 1
    else:
        return n * fact_r(n - 1)

#Función para medir tiempo y memoria
def medir_rendimiento(func, n):
    tracemalloc.start()
    start = time.perf_counter()
    resultado = func(n)
    end = time.perf_counter()
    memoria_actual, pico_memoria = tracemalloc.get_traced_memory()
    tracemalloc.stop()
    tiempo = end - start
    return resultado, tiempo, pico_memoria / 1024  # en KB

if __name__ == "__main__":
    # Puntos de referencia
    valores_n = [100, 200, 300, 400, 500, 600, 700, 800, 900, 998]
    tiempos_i, memorias_i = [], []
    tiempos_r, memorias_r = [], []

    # Calcular y mostrar factorial de 5
    res_5_i = fact_i(5)
    res_5_r = fact_r(5)
    print(f"Factorial iterativo y recursivo de 5 = {res_5_i}")
    print("-" * 50)

    # Medir con puntos de referencia grandes
    for n in valores_n:
        _, t_i, m_i = medir_rendimiento(fact_i, n)
        _, t_r, m_r = medir_rendimiento(fact_r, n)
        tiempos_i.append(t_i)
        memorias_i.append(m_i)
        tiempos_r.append(t_r)
        memorias_r.append(m_r)
        print(f"n = {n} -> Iterativo: {t_i:.8f} s, {m_i:.4f} KB | Recursivo: {t_r:.8f} s, {m_r:.4f} KB")

    # Gráfica tiempo
    plt.figure(figsize=(10, 5))
    plt.plot(valores_n, tiempos_i, marker="o", label="Iterativo", color="blue")
    plt.plot(valores_n, tiempos_r, marker="o", label="Recursivo", color="pink")
    plt.title("Tiempo de Ejecución: Comparación")
    plt.xlabel("n")
    plt.ylabel("Tiempo (s)")
    plt.grid(True)
    plt.legend()
    plt.show()

    # Gráfica memoria
    plt.figure(figsize=(10, 5))
    plt.plot(valores_n, memorias_i, marker="o", label="Iterativo", color="blue")
    plt.plot(valores_n, memorias_r, marker="o", label="Recursivo", color="pink")
    plt.title("Uso de Memoria: Comparación")
    plt.xlabel("n")
    plt.ylabel("Memoria (KB)")
    plt.grid(True)
    plt.legend()
    plt.show()
