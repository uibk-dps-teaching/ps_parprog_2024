#include <omp.h>
#include <stdio.h>

int main() {

    int data;
    int flag = 0;

    #pragma omp parallel num_threads(2)
    {
      if (omp_get_thread_num() == 0) {

          data = 42;

          flag = 1;

      } else if(omp_get_thread_num() == 1) {
        
          int flag_val = 0;

          while (flag_val < 1) {
             
             flag_val = flag;

          }

          printf("flag=%d data=%d\n", flag, data);

          printf("flag=%d data=%d\n", flag, data);

      }
    }
    return 0;
}
