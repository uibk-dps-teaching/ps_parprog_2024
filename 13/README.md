# Assignment 13

The goal of this assignment is to implement a 3D n-body simulation.

## Exercise 1 (3 Points)

### Description

N-body simulations form a large class of scientific applications, as they are used in research ranging from astrophysics to molecular dynamics. At their core, they model and simulate the interaction of moving particles in physical space. For this assignment, the specific n-body setting relates to astrophysics, where the mutual gravitational effect of stars is investigated. Each particle has several properties which include at least

- position,
- velocity, and
- mass.

For each timestep (you can assume `dt = 1`), particles must be moved by first computing the force exerted on them according to the [Newtonian equation for gravity](https://en.wikipedia.org/wiki/Newton%27s_law_of_universal_gravitation), `force = G * (mass_1 * mass_2) / radius^2` where `G` is the gravitational constant (and can be assumed as `G = 1` for simplicity). Second, using the computed force on a particle, its position and velocity can be updated via `velocity = velocity + force / mass` and `position = position + velocity`.

### Tasks

1) Provide a sequential implementation of the n-body simulation in 3D. Hints on how to proceed (not mandatory to follow):
  a. generate particles randomly, e.g. uniformly distributed
  b. provide a function for computing forces and moving particles
  c. move particles in a time loop for a given number of steps
2) Measure the execution time for various particle numbers and timesteps. What can you observe?
3) Implement a parallel version the n-body simulation. Optimize your code as much as possible, consider all the optimizations that we discussed this course. Which optimizations are suitable for this kind of problem? Benchmark your optimized version for multiple numbers of threads and discuss the results.
4) Write your data to a file (e.g. `data.dat` ) and use any visualization tool to visualize the movement of the data
    Here is an example using `gnuplot`:

    a. ````
        set terminal gif animate delay 100  # set gif to animate in a frame delay of 100 ms
        set output 'output.gif' # write to the file output.gif

        set style line 2 lc rgb 'black' pt 7   # set line to be a filled circle of color black
        stats 'data.dat' nooutput # read data from data.dat file 
        set xrange [-0.5:100.5] # print data values for x axis from range [-0.5:100.5]
        set yrange [-0.5:100.5] # print data values for y axis from range [-0.5:100.5]
        set zrange [-0.5:100.5] # print data values for z axis from range [-0.5:100.5]

        do for [i=1:int(STATS_blocks)] {
           splot 'data.dat' index (i-1) with points ls 2 ps 0.4 #for each datapoint plot the point
        }
       ````
    b. use this [gnuplot](particle.plt) snippet to create a gif, adapt this file according to your particle range implementation
    c. the data for the previous example has to be in following format:
        ````
            x1_timestep1 y1_timestep1 z1_timestep1
            x2_timestep1 y2_timestep1 z2_timestep1
            x3_timestep1 y3_timestep1 z3_timestep1


            x1_timestep2 y1_timestep2 z1_timestep2
            x2_timestep2 y2_timestep2 z2_timestep2
            x3_timestep2 y3_timestep2 z3_timestep2


            x1_timestep3 y1_timestep3 z1_timestep3
            x2_timestep3 y2_timestep3 z2_timestep3
            x3_timestep3 y3_timestep3 z3_timestep3
        ````
       So in one line there is an x, y, and z value for a point, multiple points are in different lines. 
       Having 2 blank lines means the points for this timestep are finished. Note that all values can be floating point numbers
5) For measuring performance either disable writing to a datafile or consider not dumping each timestep
6) Benchmark the sequential program and the parallelized version using 5000 particles and 100 time steps for 12 threads on LCC3 and enter the results in the comparison spreadsheet linked on Discord.

## General Notes

All the material required by the tasks above (e.g., code, figures, text, etc...) must be part of the solution that is handed in. Your experiments should be reproducible and comparable to your measurements using the solution materials that you hand in.

**Every** member of your group must be able to explain the given problem, your solution, and possible findings. You may also need to answer detailed questions about any of these aspects.
