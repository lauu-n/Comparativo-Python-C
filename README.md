# Comparativo de Factorial Recursivo vs Iterativo en Python y C

## 📌 Propósito de la tarea
La comparación se realiza en **Python** y **C**, evaluando el **tiempo de ejecución** y el **uso de memoria** para cada implementación.  

El objetivo es implementar y comparar dos enfoques para calcular el factorial de un número entero positivo:  
1. Recursivo  
2. Iterativo  

---

## 🖥 Implementación de las Funciones

### Python

**Iterativo:**  
<br>
<img width="303" height="182" alt="Iterativo Python" src="https://github.com/user-attachments/assets/49e3578c-a306-47e7-a45a-09fbc2567c57" />  

**Recursivo:**  
<br>
<img width="348" height="177" alt="Recursivo Python" src="https://github.com/user-attachments/assets/01a4e8cc-6898-4e6e-ae3d-c70f0a668bb5" />  

---

### C

**Iterativo:**  
<br>
<img width="487" height="146" alt="Iterativo C" src="https://github.com/user-attachments/assets/3c1054bb-775c-47c9-9421-629494c3a15e" />  

**Recursivo:**  
<br>
<img width="469" height="103" alt="Recursivo C" src="https://github.com/user-attachments/assets/5bc41674-dd7f-4d61-9082-ede19a419ad0" />  

---

## ⏱ Métodos de Medición

### Python
- **Tiempo:** `time.perf_counter()` para alta precisión  
- **Memoria:** `tracemalloc` para capturar el pico de memoria (en KB)  

### C
- **Tiempo:** `clock_gettime(CLOCK_MONOTONIC, ...)` para medir con alta resolución  
- **Memoria:** Lectura de `/proc/self/statm` en Linux y conversión usando `sysconf(_SC_PAGESIZE)`  

---

## 📊 Resultados & Hallazgos

### Velocidad
- En Python, el **iterativo** es más rápido que el recursivo para valores grandes de `n`.  
- En C, ambos son rápidos, pero el **iterativo** es ligeramente más eficiente.  

### Memoria
- El recursivo consume más memoria por la acumulación de llamadas en la pila.  
- El iterativo mantiene un uso casi constante.  

---

## 📈 Gráficos

### Python

**Recursivo:**  
<br>
<img width="739" height="558" alt="Recursivo Tiempo Python" src="https://github.com/user-attachments/assets/86a06d75-0af2-4522-b369-82d5c6640da8" />  
<img width="679" height="546" alt="Recursivo Memoria Python" src="https://github.com/user-attachments/assets/5ed4a8b1-f224-47c5-b0e0-7f5488f65b03" />  

**Iterativo:**  
<br>
<img width="733" height="557" alt="Iterativo Tiempo Python" src="https://github.com/user-attachments/assets/5d04cb46-017b-4f82-9ea9-632de9dd1cbd" />  
<img width="700" height="540" alt="Iterativo Memoria Python" src="https://github.com/user-attachments/assets/ed09fb96-2171-4e6d-a8c6-422572265a65" />  

---

### C  
*(Aquí irán las gráficas correspondientes a C)*  

---
