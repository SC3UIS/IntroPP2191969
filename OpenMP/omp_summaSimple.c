/*
 * Este codigo es proporcionado del github que nos proporciono el profesor a cargo de la asignatura, es el siguiente: https://github.com/carlosjaimebh/SomeExamples/blob/main/summaSimple.c
 * */

#include <stdio.h>
#include <omp.h>

int main()
{
    int num, count, sum = 0;

    printf("Enter a positive integer: ");
    scanf("%d", &num);
/*En este bloque de código se utiliza la directiva pragma omp para crear un equipo de hilos y distribuir el trabajo del bucle for en paralelo. 
La cláusula parallel indica que el siguiente bloque de código se ejecutará en paralelo. 
La cláusula for indica que se debe distribuir el trabajo del bucle for entre los hilos creados. 
La cláusula reduction indica que la variable sum debe ser compartida entre los hilos, y que cada hilo debe mantener una copia privada de la variable. 
Al final del bucle, los valores de todas las copias privadas se suman y se almacenan en la variable sum.*/
    #pragma omp parallel for reduction(+:sum)
    for(count = 1; count <= num; ++count)
    {
        sum += count;
    }

    printf("\nSum = %d\n", sum);

    return 0;
}