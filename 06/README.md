# Assignment 6

## Exercise 1 (1 Point)

### Description

Consider the following individual code snippets, and analyze them regarding dependencies.

```c
for (int i=0; i < n-1; i++) {
    x[i] = (y[i] + x[i+1]) / 7;
}
```

```c
for (int i=0; i < n; i++) {
    a = (x[i] + y[i]) / (i+1);
    z[i] = a;
}

f = sqrt(a + k);
```

```c
for (int i=0; i < n; i++) {
   x[i] = y[i] * 2 + b * i;
}


for (int i=0; i < n; i++) {
   y[i] = x[i]  + a / (i+1);
}
```

### Tasks

Regarding each snippet

1) What are the data dependencies?
2) Parallelize and optimize the code

## Exercise 2 (1 Point)

### Description

In this exercise we try to parallelize loops which have data dependencies.
Look at the following individual code snippets.
a)

```c
double factor = 1;

for (int i=0; i < n; i++) {
    x[i] = factor * y[i];
    factor = factor / 2;
}
```

b)

```c
for (int i = 1; i<n; i++) {
    x[i] = (x[i] + y[i-1]) / 2;
    y[i] = y[i] + z[i] * 3;
}
```

c)

```c
x[0] = x[0] + 5 * y[0];
for (int i = 1; i<n; i++) {
    x[i] = x[i] + 5 * y[i];
    if ( twice ) {
        x[i-1] = 2 * x[i-1]
    }
}
```

### Tasks

1) Where are the data dependencies?
2) How can you parallelize the loops?
3) Implement the original and parallelized versions and compare their wall time for reasonable sizes and numbers of threads.

## Exercise 3 (1 Point)

### Description

```c
for (int i = 0; i < 4; ++i) {
    for (int j = 1; j < 4; ++j) {
        a[i + 2][j - 1] = b * a[i][j] + 4;
    }
}
```

### Tasks

1) For each iteration, give the corresponding distance and direction vectors
2) What type of dependence is represented in this code snippet?
3) How would you parallelize this code?

## General Notes

All the material required by the tasks above (e.g., code, figures, text, etc...) must be part of the solution that is handed in. Your experiments should be reproducible and comparable to your measurements using the solution materials that you hand in.

**Every** member of your group must be able to explain the given problem, your solution, and possible findings. You may also need to answer detailed questions about any of these aspects.
