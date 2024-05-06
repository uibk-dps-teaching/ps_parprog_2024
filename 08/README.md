# Assignment 8

The goal of this assignment is to gain more experience in parallelizing programs with OpenMP.

## Exercise 1 (1.5 Points)

### Description

This exercise consists of exploring the effects of OpenMP thread affinity.

### Tasks

1) Write an OpenMP program that atomically increments an `int` using `#pragma omp atomic` in a parallel for loop for a large number of iterations, i.e. such that the program takes at least 2 seconds to execute. Have the program print the time required to process the entire loop. Compile your program with gcc 12.2.0 and optimization level `-O3`. Do not perform any manual optimizations such as reducing the number of atomic operations.
2) Run your program with 6 threads. Explore the affinity features of OpenMP 4.0 to change the way threads are mapped to cores, e.g. using a single CPU only or using both CPUs. Explain the affinity settings that you chose.
3) Benchmark your program with these affinity settings. What can you observe?
4) Enter the time for N=500.000.000 into the comparison spreadsheet linked on Discord.

## Exercise 2 (1.5 Points)

### Description

This exercise consists of extending the Hadamard product implementation of the previous assignment.

### Tasks

1) Implement parallel versions of both snippets of the Hadamard product of Assignment 3 Exercise 2 using OpenMP.
2) Benchmark your serial implementations and your parallel implementations with 1, 2, 4, 6 and 12 threads on LCC3 using N=10.000², 20.000² and 30.000². Use OpenMP's time measurement function to measure only the computational loop.
3) Use the 3 loop scheduling methods discussed in the lecture, `static`, `dynamic` and `guided`. Explain their differences and compare their performance for the two code snippets. What can you observe?
4) In addition, try the loop scheduling methods `auto` and `runtime`. What do they do, what can you observe?
5) Enter the time for N=65.536² into the comparison spreadsheet linked on Discord.

## General Notes

All the material required by the tasks above (e.g., code, figures, text, etc...) must be part of the solution that is handed in. Your experiments should be reproducible and comparable to your measurements using the solution materials that you hand in.

**Every** member of your group must be able to explain the given problem, your solution, and possible findings. You may also need to answer detailed questions about any of these aspects.
