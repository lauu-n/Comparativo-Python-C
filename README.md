# Comparativo de Factorial Recursivo vs Iterativo en Python y C

##  Propósito de la tarea
La comparación se realiza en **Python** y **C**, evaluando el **tiempo de ejecución** y el **uso de memoria** para cada implementación.  

El objetivo es implementar y comparar dos enfoques para calcular el factorial de un número entero positivo:  
1. Recursivo  
2. Iterativo  

---

##  Implementación de las Funciones

### Python

**Iterativo:**  
<br>
<img width="200" height="100" alt="image" src="https://github.com/user-attachments/assets/b1f5cd15-e292-4973-824b-549236dd2fb7" />


**Recursivo:**  
<br>
<img width="200" height="100" alt="image" src="https://github.com/user-attachments/assets/457933fc-c83e-4d76-b072-3c93f0fe1d9a" />


---

### C

**Iterativo:**  
<br>
<img width="380" height="229" alt="image" src="https://github.com/user-attachments/assets/ca788fc5-c802-4dc5-8aae-a0aa825346dc" />


**Recursivo:**  
<br>
<img width="359" height="161" alt="image" src="https://github.com/user-attachments/assets/76d2500c-3dcd-48fa-8e46-a49c46e49330" />


---

##  Métodos de Medición

### Python
- **Tiempo:** `time.perf_counter()`
- **Memoria:** `tracemalloc` para capturar el pico de memoria (en KB)  

### C
- **Tiempo:** `clock_gettime(CLOCK_MONOTONIC, ...)` 
- **Memoria:** Lectura de `/proc/self/statm` en Linux y conversión usando `sysconf(_SC_PAGESIZE)`  

---

##  Resultados & Hallazgos

### Velocidad
- En Python, el **iterativo** es más rápido que el recursivo para valores grandes de `n`.  
- En C, ambos son rápidos, pero el **iterativo** es ligeramente más eficiente.  

### Memoria
- El recursivo consume más memoria por la acumulación de llamadas en la pila.  
- El iterativo mantiene un uso casi constante.  

---

##  Gráficos

### Python

**Tiempo de ejecución**  
<br>
<img width="1113" height="591" alt="image" src="https://github.com/user-attachments/assets/ae4a56f6-fe57-451a-84e1-f98025290614" />


**Uso de memoria:**  
<br>
<img width="1101" height="583" alt="image" src="https://github.com/user-attachments/assets/2fb78273-4038-45b6-b3af-3a3234024596" />


---

##  Conclusiones

- Para tareas que requieran eficiencia en memoria y velocidad, el enfoque iterativo es más adecuado.
- El recursivo, aunque más elegante y fácil de entender, es menos eficiente en memoria y puede verse limitado por la profundidad de la pila.

---

##  Laura Niño
