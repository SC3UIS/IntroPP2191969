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
