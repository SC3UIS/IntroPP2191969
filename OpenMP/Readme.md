# Introducción al trabajo:

En esta primera entrega, dividida en cinco partes, tiene como objetivo evaluar las competencias adquiridas en torno a la transformación de códigos que se encuentran implementados en C/C++ para su ejecución paralela usando OpenMP. Cada uno de los estudiantes recibirá un correo electrónico personalizado que contendrá la descripción y encabezado del código recibido (en inglés principalmente), junto con el código respectivo (en .c). Este código se encuentra debidamente documentado y licenciado para su uso bajo una licencia GPL .

# Funcionamiento:

Se explica el funcionamiento del código, opciones de compilación y cómo se ejecuta tanto en su máquina local como en GUANE-1.

# Desarrollo:

En este proyecto se evaluaron las habilidades adquiridas en la transformación de códigos de programación en C para su ejecución en paralelo mediante el uso de la biblioteca OpenMP. La metodología utilizada para la evaluación y entrega consistió en la creación de una cuenta en Github, la vinculación con el equipo de Supercomputación y Cálculo Científico "beginners-hpc" de la Universidad Industrial de Santander (SC3UIS), y la creación de un repositorio que incluyera el código original en C, la versión modificada para ejecución en paralelo con OpenMP, el archivo sbatch para la ejecución en el sistema GUANE-1, el archivo README con la descripción del código y sus opciones de compilación y ejecución, y el archivo de salida con los resultados obtenidos. Esta evaluación permitió poner en práctica y demostrar el conocimiento adquirido en programación paralela con OpenMP, y su aplicación en el contexto de la supercomputación y el cálculo científico.

# Objetivo:

Aplicar los fundamentos de OpenMP vistos en clase y en la bibliografía relacionada para paralelizar el código original, manteniendo el estilo de la documentación y agregando una sección que explique las modificaciones realizadas en la versión en OpenMP.

# Explicaciones Codigos Proporcionados:

# Archivo llamado omp_summaSimple.c

include <stdio.h>
include <omp.h>

int main()
{
    int num, count, sum = 0;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    #pragma omp parallel for reduction(+:sum)
    for(count = 1; count <= num; ++count)
    {
        sum += count;
    }
     printf("\nSum = %d\n", sum);
    return 0;
}

Este código en C utiliza la biblioteca OpenMP (Open Multi-Processing) para crear un equipo de hilos y distribuir el trabajo de un bucle for en paralelo. La biblioteca OpenMP es una API (Application Programming Interface) para programación paralela de memoria compartida en sistemas multiprocesador.
En particular, el código pide al usuario que ingrese un número entero positivo y luego utiliza una directiva pragma omp para crear un equipo de hilos y distribuir el trabajo del bucle for en paralelo. La cláusula parallel indica que el siguiente bloque de código se ejecutará en paralelo. La cláusula for indica que se debe distribuir el trabajo del bucle for entre los hilos creados. La cláusula reduction indica que la variable sum debe ser compartida entre los hilos, y que cada hilo debe mantener una copia privada de la variable. Al final del bucle, los valores de todas las copias privadas se suman y se almacenan en la variable sum.
En este caso, el bucle for se utiliza para calcular la suma de los primeros "num" números enteros. En cada iteración del bucle, el contador "count" se incrementa en uno y se suma al valor actual de "sum". Después de que todos los hilos han terminado de ejecutar su parte del bucle, los valores de "sum" de cada hilo se suman juntos y se almacenan en la variable "sum". Finalmente, se imprime el valor de "sum" en la pantalla.

La directiva #pragma omp parallel for reduction(+:sum) se utiliza en programación paralela con OpenMP para indicar que un bucle for debe ser ejecutado en paralelo por varios hilos, y que el valor de una variable (sum en este caso) debe ser agregado en una operación de reducción al final de la ejecución del bucle.

La cláusula parallel indica que el siguiente bloque de código debe ser ejecutado en paralelo por varios hilos, y la cláusula for indica que el bucle for que sigue a continuación debe ser dividido en subrangos que serán ejecutados por diferentes hilos. Por lo tanto, cada hilo ejecutará una parte del bucle for en paralelo.

La cláusula reduction(+:sum) indica que la variable sum debe ser compartida entre los hilos, y que cada hilo debe mantener una copia privada de la variable. Al final de la ejecución del bucle, el valor de cada copia privada de sum es agregado mediante una operación de reducción (+ en este caso) y el resultado final es almacenado en la variable sum original.

En resumen, la directiva #pragma omp parallel for reduction(+:sum) se utiliza para paralelizar la ejecución de un bucle for y agregar el resultado en una variable compartida de manera segura, utilizando la operación de reducción. Esto puede mejorar significativamente el rendimiento de los programas que realizan operaciones repetitivas intensivas, al permitir que varias tareas sean ejecutadas en paralelo por varios hilos.

# Archivo llamado summaSimple.c (Archivo del profesor)

include <stdio.h>
int main()
{
    int num, count, sum = 0;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    // for loop terminates when num is less than count
    for(count = 1; count <= num; ++count)
    {
        sum += count;
    }
    printf("\nSum = %d\n", sum);
    return 0;
}

Este código en C es un programa simple que calcula la suma de los primeros números enteros positivos, proporcionado por el usuario.

El programa comienza solicitando al usuario que ingrese un número entero positivo utilizando la función printf() y scanf(). Este número se almacena en la variable num.

A continuación, se utiliza un bucle for para iterar desde 1 hasta el valor de num. En cada iteración, el contador count se incrementa en uno y se suma al valor actual de la variable sum. De esta manera, al final del bucle, la variable sum contendrá la suma de los primeros num números enteros.

Por último, el programa utiliza la función printf() para imprimir el valor de sum en la pantalla.

En resumen, este programa es una implementación simple de la fórmula de la suma de los primeros num números enteros positivos, utilizando un bucle for para realizar la operación de suma.


# Ejecucion en Guane-1

***

# Conclusiones:

En conclusión, este trabajo de programación paralela utilizando OpenMP y Github fue una oportunidad valiosa para adquirir habilidades y conocimientos importantes en dos áreas fundamentales de la informática: la programación paralela y la gestión de proyectos de software colaborativo.

En particular, el trabajo permitió comprender la importancia y los beneficios de la programación paralela en el rendimiento de aplicaciones informáticas que requieren procesamiento intensivo, y cómo OpenMP puede utilizarse para aprovechar el potencial de los sistemas multicore y multiprocesador.

Asimismo, la experiencia en Github permitió aprender sobre la gestión de versiones, el trabajo colaborativo y la documentación de proyectos de software, habilidades fundamentales en la actualidad para el desarrollo de software en equipos distribuidos.

En conjunto, este trabajo proporcionó una valiosa oportunidad para mejorar habilidades y conocimientos importantes en programación paralela y gestión de proyectos de software, que pueden ser aplicados en futuros proyectos y en la resolución de problemas informáticos complejos que requieran de alto rendimiento y colaboración entre equipos.



