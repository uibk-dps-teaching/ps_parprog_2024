# Assignment 1

The goal of this assignment is to get you acquainted with working on an HPC cluster as well as obtaining, illustrating, and interpreting measurement data.

## Exercise 1 (1.5 Points)

### Description

This exercise consists in familiarizing yourself with SLURM job submission.

You received user credentials for the LCC3 cluster. If you did not change the default password, do so **immediately**. You are responsible for this account during this semester.

You can find information about LCC3 at https://www.uibk.ac.at/zid/systeme/hpc-systeme/leo3/ and information about SLURM job submission at https://www.uibk.ac.at/zid/systeme/hpc-systeme/common/tutorials/slurm-tutorial.html.

**Please run any benchmarks or heavy CPU loads only on the compute nodes, not on the login node.**
If you want to do some interactive experimentation, use an *interactive job* as outlined in the tutorial. Make sure to stop any interactive jobs once you are done.

### Tasks

- Study how to submit jobs in SLURM, how to check their state and how to cancel them.
- Prepare a submission script that starts an arbitrary executable, e.g. `/bin/hostname`
- In your opionion, what are the 5 most important parameters available when submitting a job and why? What are possible settings of these parameters, and what effect do they have?
- How do you run your program in parallel? What environment setup is required?

## Exercise 2 (1.5 Points)

This exercise consists in running and comparing two parallel implementations of the same algorithm.

### Description

There are usually multiple implementations to choose from putting an algorithm into source code. In this exercise, we will compare the behavior of three different parallel implementations that all do the same thing: They simply sum up numbers, measure the time required to do so, and finally both print the calculated sum and the time.

### Tasks

- Compile the three given source codes `slow.c`, `medium.c`, and `fast.c` with the compiler flag `-fopenmp` to enable OpenMP parallelism.
- Vary the number of cores by setting the environment variable `OMP_NUM_THREADS` before running the program, e.g. `OMP_NUM_THREADS=1 ./slow`. Measure the execution times of all three programs for all numbers of cores your personal computing system (e.g. PC or laptop) offers.
- See if you can reduce the execution times even further by trying out different compiler flags (optimization flags).
- Create a table and figures that illustrate the measured data and study them. What effects can you observe?
- How stable are the measurements when running the experiments multiple times?
- Enter the shortest execution times for 1 and 12 threads measured on the LCC3 cluster for each code to the performance comparison sheet linked on Discord.

## General Notes

All the material required by the tasks above (e.g. code, figures, text, etc...) must be part of the solution that is handed in. Your experiments should be reproducible and comparable to your own measurements using the solution materials that you hand in.

**Every** member of your group must be able to explain the given problem, your solution, and possible findings. You may also need to answer detailed questions about any of these aspects.
