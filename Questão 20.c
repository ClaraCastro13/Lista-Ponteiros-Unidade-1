#include <stdio.h>
#include <stdlib.h>
#include "gc.h"
#include <assert.h>
#include <time.h>

int main(void)
{
  const int size = 10000000;
  clock_t t, t1;

  t = clock();
  
  GC_INIT();
  
  for (int i = 0; i < size; ++i)
  {
    int **p = GC_MALLOC(sizeof(int));
  }
  t = clock() - t;
  printf("%f segundos", ((float)t)/CLOCKS_PER_SEC);

  t1 = clock();
  
  for (int i = 0; i < size; ++i)
  {
    int **q = malloc(sizeof(int));
    free(q);
  }

    t1 = clock() - t1; 
    printf("%f segundos", ((float)t1)/CLOCKS_PER_SEC);

    return 0;
}