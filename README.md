# Comparativo de Factorial Recursivo vs Iterativo en Python y C

## Propósito de la tarea  
El objetivo de esta práctica es implementar y comparar dos enfoques para calcular el factorial de un número entero positivo:
  1. Recursivo  
  2. Iterativo  
La comparación se realiza en Python y C evaluando el **tiempo de ejecución** y el **uso de memoria** para cada implementación.
---
## Implementación de las funciones  
### **Python**
~Iterativo:  
def fact_i(n):  
    if n < 0:  
        return "Error"  
    result = 1  
    for i in range(1, n + 1):  
        result *= i  
    return result  
~Recursivo:  
  def facto_r(n):  
      if n < 0:  
          return "Error"  
      elif n == 0 or n == 1:  
          return 1  
      else:  
          return n * facto_r(n - 1)  
### **C**  
~Iterativo:  
unsigned long long factorial_iterativo(int n)  
  {  
    unsigned long long resultado = 1;  
    for (int i = 1; i <= n; ++i)  
        resultado *= i;  
    return resultado;  
  }  
~Recursivo:  
unsigned long long factorial_recursivo(int n) {  
    if (n <= 1) return 1;  
    return n * factorial_recursivo(n - 1);  
}  
