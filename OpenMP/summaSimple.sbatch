#!/bin/bash
#SBATCH --job-name=summaSimple       
#SBATCH --output=output_summaSimple.txt    
#SBATCH --error=summaSimple_err.txt 
#SBATCH --ntasks=4                  
#SBATCH --cpus-per-task=4

gcc -fopenmp omp_summaSimple.c -o omp_summaSimple
./omp_summaSimple