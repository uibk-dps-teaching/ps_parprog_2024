#define _POSIX_C_SOURCE 199506L

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>
#include <time.h>

#define START_SEED 0

typedef uint64_t timepoint_t;
typedef uint32_t count_t;

struct MonteCarloPiInput {
    count_t iterations;
    uint32_t id;
};

static void* monte_carlo_pi(void* arg);
static timepoint_t time_ns();
static double elapsed_seconds(timepoint_t start, timepoint_t end);

int main(int argc, char** argv) {
    // read input arguments
    if (argc > 2) {
        fprintf(stderr, "Usage: %s [<thread_count>]\n", argv[0]);
        return EXIT_FAILURE;
    }

    const int32_t requested_threads = (argc <= 1) ? 1 : atoi(argv[1]);
    const uint32_t num_threads = (requested_threads < 1) ? 1 : (uint32_t) requested_threads;

    const count_t total_iterations = ((count_t) 700) * 1000 * 1000;
    const count_t per_thread_iterations = total_iterations / num_threads;
    
    bool simulation_success = true;

    // start time measurement
    timepoint_t start = time_ns();

    // create and start threads
    pthread_t threads[num_threads];
    struct MonteCarloPiInput inputs[num_threads];
    int creation_statuses[num_threads];

    for (uint32_t i = 0; i < num_threads; ++i) {
        inputs[i] = (struct MonteCarloPiInput) {
            .id = i,
            .iterations = per_thread_iterations + ((i == 0) ? (total_iterations % num_threads) : 0)
        };

        creation_statuses[i] = pthread_create(&threads[i], NULL, monte_carlo_pi, (void*) &inputs[i]);

        if (creation_statuses[i] != 0) {
            fprintf(stderr, "Failed to create thread %u with error %d\n", i, creation_statuses[i]);
            simulation_success = false;
        }
    }

    // join threads and calculate result
    count_t points_in_circle = 0;
    for (uint32_t i = 0; i < num_threads; ++i) {
        if (creation_statuses[i] == 0) {
            count_t* result = NULL;
            int status = pthread_join(threads[i], (void**) &result);

            if (status != 0) {
                fprintf(stderr, "Joining thread %u failed with error %d\n", i, status);
                simulation_success = false;
            } else if (result != NULL) {
                points_in_circle += *result;
                free(result);
            }
        }
    }

    double pi_approximation = 4.0 * (points_in_circle / (double) total_iterations);

    // print result and elapsed time    
    timepoint_t end = time_ns();
    double elapsed_time = elapsed_seconds(start, end);

    if (simulation_success) {
        printf("Approximation of PI took %.3f seconds with %u threads - value: %.10f\n",
               elapsed_time, num_threads, pi_approximation);
    } else {
        printf("Simulation failed!\n");
    }

    return (simulation_success) ? EXIT_SUCCESS : EXIT_FAILURE;
}

static void* monte_carlo_pi(void* arg) {
    struct MonteCarloPiInput* input = (struct MonteCarloPiInput*) arg;
    unsigned int seed = START_SEED + input->id;

    count_t* points_in_cricle = calloc(1, sizeof(count_t));

    for (count_t i = 0; i < input->iterations; ++i) {
        float x = (rand_r(&seed) / (float) RAND_MAX);
        float y = (rand_r(&seed) / (float) RAND_MAX);
        
        if (x * x + y * y <= 1.0f) {
            ++(*points_in_cricle);
        }
    }

    // implicit call to pthread_exit()
    return (void*) points_in_cricle;
}

static timepoint_t time_ns() {
    // Note: We assume that all time information fits into an uint64_t
    struct timespec now;
    clock_gettime(CLOCK_MONOTONIC, &now);
    return ((timepoint_t) now.tv_sec) * ((timepoint_t) 1E9) + now.tv_nsec;
}

static double elapsed_seconds(timepoint_t start, timepoint_t end) {
    return ((start > end) ? start - end : end - start) / 1E9;
}
