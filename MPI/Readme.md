
# Tiempo de ejecución para los tres archivos diferentes.

# ARCHIVO mpi_summaSimple.C

[sdamendozaa@guane MPI_1]$ time mpirun -np 12 ./mpi_Simple
Enter a positive integer: 12

Sum = 78

real    0m3.492s
user    0m35.465s
sys     0m2.251s

![image](https://github.com/SC3UIS/IntroPP2191969/assets/105290908/ea899e6f-d9da-4b45-be08-356bbe21731c)


# ARCHIVO summaSimple.C

[sdamendozaa@guane MPI_1]$ gcc summaSimple.C -o summa
[sdamendozaa@guane MPI_1]$ time ./summa
Enter a positive integer: 12

Sum = 78

real    0m2.446s
user    0m0.001s
sys     0m0.002s

![image](https://github.com/SC3UIS/IntroPP2191969/assets/105290908/ff373790-ae3f-499e-8470-be1eb0b1ef38)



# ARCHIO omp_summaSimple.C
[sdamendozaa@guane OpenMP]$ time ./omp_Simple
Enter a positive integer: 12

Sum = 78

real    0m1.977s
user    0m0.000s
sys     0m0.008s

![image](https://github.com/SC3UIS/IntroPP2191969/assets/105290908/088595c6-6635-4888-9d0a-64aee8d56869)


Explicación ajustes realizados al codigo para convertirlo de OMP A MPI.

// Simple Program to calculate the sum of first n natural numbers
// Positive integers 1,2,3...n are known as natural numbers

#include <stdio.h>
#include <mpi.h>

int main()
{
    int num, count, sum = 0;
    int rank, size;

    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        printf("Enter a positive integer: ");
        scanf("%d", &num);
    }

    MPI_Bcast(&num, 1, MPI_INT, 0, MPI_COMM_WORLD);

    int start = rank * (num / size) + 1;
    int end = (rank + 1) * (num / size);

    if (rank == size - 1) {
        end = num;
    }

    for (count = start; count <= end; ++count)
    {
        sum += count;
    }

    int totalSum = 0;
    MPI_Reduce(&sum, &totalSum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("\nSum = %d\n", totalSum);
    }

    MPI_Finalize();

    return 0;
}


1)#include <stdio.h>: Incluye la biblioteca estándar de entrada/salida para utilizar funciones como printf y scanf.

2)#include <mpi.h>: Incluye la biblioteca MPI para el desarrollo de programas paralelos con MPI.

3)int main(): Función principal del programa.

4)int num, count, sum = 0;: Declaración de variables enteras para almacenar el número ingresado por el usuario, el contador y la suma parcial de cada hilo.

5)int rank, size;: Variables para almacenar el rango (identificador) y el tamaño del comunicador MPI.

6)MPI_Init(NULL, NULL);: Inicialización del entorno MPI.

7)MPI_Comm_rank(MPI_COMM_WORLD, &rank);: Obtiene el rango (identificador) del proceso actual en el comunicador global MPI_COMM_WORLD.

8)MPI_Comm_size(MPI_COMM_WORLD, &size);: Obtiene el tamaño del comunicador global MPI_COMM_WORLD.

9)if (rank == 0) { ... }: Bloque condicional que solo se ejecuta en el proceso con rango 0. En este caso, el proceso 0 se encarga de solicitar al usuario el ingreso de un número entero.

10)scanf("%d", &num);: Lee el número entero ingresado por el usuario y lo almacena en la variable num.

11)MPI_Bcast(&num, 1, MPI_INT, 0, MPI_COMM_WORLD);: El proceso 0 transmite el valor de num a todos los demás procesos del comunicador MPI_COMM_WORLD.

12)int start = rank * (num / size) + 1;: Cada proceso calcula el inicio del rango de números que debe sumar.

13)int end = (rank + 1) * (num / size);: Cada proceso calcula el final del rango de números que debe sumar.

14)if (rank == size - 1) { end = num; }: El último proceso ajusta el final del rango para incluir los números restantes.

15)for (count = start; count <= end; ++count) { sum += count; }: Cada proceso realiza la suma parcial de los números en su rango asignado.

16)int totalSum = 0;: Variable para almacenar la suma total de todos los procesos.

17)MPI_Reduce(&sum, &totalSum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);: Cada proceso reduce su suma parcial y la envía al proceso 0 para obtener la suma total.

18)if (rank == 0) { printf("\nSum = %d\n", totalSum); }: El proceso 0 imprime la suma total calculada.

19)MPI_Finalize();: Finalización del entorno MPI.

20)return 0;: Finaliza la ejecución del programa.
