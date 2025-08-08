# Comprativo eficiencia: Factorial Recursivo vs Iterativo
## Descripción & Propósito
Este proyecto tiene como objetivo comparar la eficiencia en el cálculo del factorial de un número, utilizando dos lenguanjes: Python y C.  
Para cada lenguaje se implementaron dos funciones:  
  ~Iterativa (Uso de bucles)  
  ~Recursiva (Llamadas a la misma función)  
El propósito principal es analizar las diferencias en tiempo de ejecución y uso de la memoria entre ambos enfoques y lenguajes.
## Implementación de Funciones
# 📊 Comparación de Factorial Recursivo vs Iterativo en Python y C

## 📌 Propósito de la tarea
El objetivo de esta práctica es **implementar y comparar** dos enfoques para calcular el factorial de un número entero positivo:

1. **Recursivo**
2. **Iterativo**

La comparación se realiza en **Python** y **C**, evaluando el **tiempo de ejecución** y el **uso de memoria** para cada implementación.

---

## ⚙️ Implementación de las funciones

### Python
- **Recursivo:**
  ```python
  def facto_r(n):
      if n < 0:
          return "Error"
      elif n == 0 or n == 1:
          return 1
      else:
          return n * facto_r(n - 1)
