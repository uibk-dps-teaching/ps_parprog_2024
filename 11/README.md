# Assignment 11
The goal of this assignment is to parallelize an unknown application using profiling and OpenMP.

## Exercise 1 (1 Point)

### Description

The file [real.tar.gz](real.tar.gz) contains a realistic implementation of a (simple) numerical algorithm. Imagine you are tasked with making this implementation faster by parallelizing it with OpenMP, without any further information. To that end, this exercise consists in analysing the performance of this application with a sample-based profiler, in order to figure out where to start with the parallelization. For simplicity, we recommend using `gprof`, but you can also use another profile of your choice, if you prefer.

As an example, using `gprof` requires three steps: First, the application needs to be compiled with `gcc` and the flag `-pg`. This causes the compiler to put instrumentation code in the executable. Then, run the application normally, which will produce a new file `gmon.out`. Finally, run `gprof <executable> gmon.out > analysis.txt` in order to obtain the analysis results. Add the `--line` flag to `gprof` if you need more fine-grained information.

### Tasks

- Obtain a performance profile of the given application by following the steps outlined above.
- Discuss the performance profile. What information does it hold and how/why is this useful?

## Exercise 2 (2 Points)

### Description

Now that we have a performance profile, we actually need to parallelize the application with OpenMP.

### Tasks

- Investigate any loops that carry larger workloads and determine if and how they can be parallelized. Parallelize them with OpenMP. Ensure that any code modification does not violate program correctness with respect to its output.
- Benchmark the original, sequential program and your parallelized version for 1, 2, 6 and 12 threads on LCC3, discuss the results and enter the data in the comparison spreadsheet linked on Discord.

## General Notes

All the material required by the tasks above (e.g., code, figures, text, etc...) must be part of the solution that is handed in. Your experiments should be reproducible and comparable to your measurements using the solution materials that you hand in.

**Every** member of your group must be able to explain the given problem, your solution, and possible findings. You may also need to answer detailed questions about any of these aspects.
