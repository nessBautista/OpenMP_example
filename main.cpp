#include <iostream>
#include <omp.h>

// Definición de constantes
#define N 100000        // Tamaño de los arreglos
#define chunk 100     // Tamaño del bloque para paralelización
#define mostrar 10    // Cantidad de elementos a mostrar en pantalla

// Declaración de función para imprimir arreglos
void imprimeArreglo(float *d);

int main()
{
    // Mensaje de inicio
    std::cout << "Sumando Arreglos en Paralelo!\n";
    
    // Declaración de los arreglos y variable de control de iteraciones
    float a[N], b[N], c[N];    // a y b son arreglos de entrada, c es el resultado
    int i;

    // Inicialización de los arreglos de entrada con valores de prueba
    for (i = 0; i < N; i++)
    {
        a[i] = i * 10;         
        b[i] = (i + 3) * 10.7;  
    }

    // Variable para controlar el tamaño de los bloques en la paralelización
    int pedazos = chunk;

    // Directiva OpenMP para paralelizar la suma de arreglos
    #pragma omp parallel for \
    shared(a, b, c, pedazos) private(i) \    
    schedule(static, pedazos)                 
    for (i = 0; i < N; i++)
        c[i] = a[i] + b[i];    // Suma elemento a elemento

    // Mostrar resultados
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a: " << std::endl;
    imprimeArreglo(a);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo b: " << std::endl;
    imprimeArreglo(b);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo c: " << std::endl;
    imprimeArreglo(c);

    return 0;
}

// Función auxiliar para imprimir los primeros 'mostrar' elementos de un arreglo
void imprimeArreglo(float *d)
{
    for (int x = 0; x < mostrar; x++)
        std::cout << d[x] << " - ";
    std::cout << std::endl;
}
