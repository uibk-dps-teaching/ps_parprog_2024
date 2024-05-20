# Assignment 10

The goal of this task is to practice using OpenMP tasks and take a first look at the heat stencil application.

## Exercise 1 (1 Point)

### Description

This exercise consists of implementing a program that calculates Delannoy numbers with OpenMP tasks.

A Delannoy number specifies the number of paths from the south-west corner of a 2D grid to the north-east corner, using only the per-step directions north, north-east, and east. See https://en.wikipedia.org/wiki/Delannoy_number for more information and a visualization.

### Tasks

- Implement a sequential program that computes the Delannoy number for a square 2D grid of size NxN where N is an input parameter for your program. If in doubt, base your implementation on the formula given in the Wikipedia article under "basic recurrence relation". Make sure your program is semantically correct by comparing the result against the Delannoy numbers given in the article.
- Parallelize your program using OpenMP tasks and benchmark both the sequential and parallel implementation for several N between 3 and ~15. What can you observe?
- What is the main bottleneck of your parallel implementation and how can it be improved without changing the underlying algorithm?
- Enter the wall clock time of the sequential version and the parallel version for 1 and 12 threads for N=12 on LCC3 to the comparison spreadsheet linked on Discord.

## Exercise 2 (2 Points)

### Description

This exercise consists of implementing a 2-dimensional heat stencil application.

A large class of scientific applications are so-called stencil or structured grid applications. These simulate time-dependent physical processes such as the propagation of heat or pressure in a given medium. The core of the simulation operates on a grid and updates each cell with information from its neighbor cells.

<img alt="heat_stencil" src="https://upload.wikimedia.org/wikipedia/commons/e/ec/2D_von_Neumann_Stencil.svg" width="40%">

### Tasks

- Given the code in [heat_stencil_2D.c](heat_stencil_2D.c), finish the implementation:
  - implement the heat propagation by updating each cell with information from its neighbors. If in doubt, you can start with the formula given in https://en.wikipedia.org/wiki/Finite_difference_method#Example:_The_Laplace_operator
  - make sure the heat source stays the same through all iterations
  - if computing the value at the boundary, use temperature at the center position as the next value (e.g if you want to calculate A[0,1], use A[0,1] as the left neighbor cell instead of the non-existent A[-1,1])
  - The simple verification at the end should pass
- Parallelize the implementation using OpenMP. Investigate the use of the `collapse` clause and explain its purpose and effects.
- Measure the time, speedup and efficiency of the stencil codes for varying problem sizes and numbers of threads.
- Enter the wall clock time of the sequential version and the parallel version for 1 and 12 threads for 500x500 on LCC3 to the comparison spreadsheet linked on Discord.

## General Notes

All the material required by the tasks above (e.g., code, figures, text, etc...) must be part of the solution that is handed in. Your experiments should be reproducible and comparable to your measurements using the solution materials that you hand in.

**Every** member of your group must be able to explain the given problem, your solution, and possible findings. You may also need to answer detailed questions about any of these aspects.
