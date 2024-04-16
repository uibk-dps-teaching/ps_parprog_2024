# Assignment 5

The goal of this assignment is to expand your knowledge on and familiarity with OpenMP.

## Exercise 1 (1.5 Points)

### Description

This exercise deals with performance analysis and improvement of a given code [ex1/ex1.c](ex1/ex1.c). The program reads a matrix size n from the command-line. Then two square matrices a and b of size n\*n are filled with random numbers. Finally, the program should print the sum of all elements of matrix c and the wall clock time after the matrix multiplication c=a\*b was conducted.

### Tasks

1) Are there any (performance) issues in the given code? Document your findings.
2) Improve the performance of the given source code.
3) Benchmark your modification of the code and the original implementation with 1, 2, 4, 6, and 12 threads on LCC3 using n=1,500. Has your effort paid off?
4) Enter your shortest wall clock time for 12 threads and n=1,500 on LCC3 to the comparison spreadsheet linked on Discord.

## Exercise 2 (1.5 Points)

### Description

This exercise deals with the OpenMP flush directive and why it can be necessary.

### Tasks

1) Examine [ex2/ex2.c](ex2/ex2.c) and explain what the code does from an abstract, high-level perspective. What should happen here?
2) Compile this code with optimization level `-O3`. Run it in an interactive job (e.g. using `salloc --exclusive --tasks-per-node=1 --cpus-per-task=1 srun --pty bash`) in a loop many times (e.g. write a loop in bash that executes it 1000 times). Run this loop repeatedly. What can you observe? **Note: Please quit your interactive job once you are done!**
3) Does this code require any `#pragma omp flush` and/or `#pragma omp atomic` directives? If it does, where are they necessary? If it does not, why not?

## General Notes

All the material required by the tasks above (e.g., code, figures, text, etc...) must be part of the solution that is handed in. Your experiments should be reproducible and comparable to your measurements using the solution materials that you hand in.

**Every** member of your group must be able to explain the given problem, your solution, and possible findings. You may also need to answer detailed questions about any of these aspects.
