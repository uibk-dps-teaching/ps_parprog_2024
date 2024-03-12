# Assignment 2

The goal of this assignment is to get you acquainted with the architecture of the LCC3 HPC cluster. Moreover, you will obtain a first grasp on the theoretical scaling characteristics of parallel programs.

## Exercise 1 (1.5 Points)

### Description

This exercise consists in familiarizing yourself with the hardware of LCC3, that you're running your applications on.

Understanding the architecture of the utilized hardware is paramount for optimizing (parallel) programs. It enables precise resource allocation, memory optimization, and strategic parallelization decisions. In this exercise, we are interested in gathering information about the hardware of the LCC3 compute nodes utilizing the [Portable Hardware Locality (hwloc)](https://www.open-mpi.org/projects/hwloc/) software package.

### Tasks

- Connect to the LCC3 compute cluster using your login credentials. Once connected, load the `hwloc` module via `module load hwloc/2.8.0-intel-2021.7.1-co55pj6`.
- Find out more about the hardware that you're running on by executing `lstopo --of txt`.
- Interpret the output and describe what information you can gather. Please also elaborate on these questions:
  - Can you retrieve the number of CPUs and cores from the output?
  - Investigate the memory hierarchy information provided by lstopo.
    - How much memory (RAM) does the compute node offer?
    - What does the term `NUMANode` tell you about the memory? Why are there two `NUMANodes`?
    - What interesting information can you retrieve about the caches of the system?
  - Is there anything else you can find out from the output?
- Based on your observations, how many threads could you utilize at maximum when parallelizing a program with OpenMP on this system?
- Compare your observations to the [LCC3 documentation](https://www.uibk.ac.at/zid/systeme/hpc-systeme/leo3/hardware/) and [CPU documentation](https://www.intel.com/content/www/us/en/products/sku/47922/intel-xeon-processor-x5650-12m-cache-2-66-ghz-6-40-gts-intel-qpi/specifications.html). Do your observations match the documentation?

## Exercise 2 (1.5 Points)

### Description

Amdahl's law is one of the most important properties of parallel programs.

### Tasks

- How is the speedup of a parallel program defined?
- What is the formal definition of Amdahl's law and what relationship does it describe for parallel programs (explain in your own words)? Why/How is this significant?
- Compute the theoretical speedup of a program that spends 10% of its time in unparallelizable, sequential regions for 6 cores and for a hypothetically unlimited number of cores.
- Compute the theoretical speedup of a program that spends 20% of its time in unparallelizable, sequential regions for 6 cores and for a hypothetically unlimited number of cores.
- Given an algorithm of time complexity O(n^3). How large (in %) can the unparallelizable, sequential region be at most, such that a speedup of 10 can be achieved using 64 cores?

## General Notes

All the material required by the tasks above (e.g. code, figures, text, etc...) must be part of the solution that is handed in. Your experiments should be reproducible and comparable to your own measurements using the solution materials that you hand in.

**Every** member of your group must be able to explain the given problem, your solution, and possible findings. You may also need to answer detailed questions about any of these aspects.