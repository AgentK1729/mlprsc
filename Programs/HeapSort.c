#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <inttypes.h>

#define N 2500
 
int64_t start, end;
int64_t timeElapsed;

long heap[N];

int64_t printHeapTime()
{
    struct timespec tms;

    
    if (clock_gettime(CLOCK_MONOTONIC,&tms)) {
        return -1;
    }
    
    int64_t micros = tms.tv_sec * 1000000;
    
    micros += tms.tv_nsec/1000;
    
    if (tms.tv_nsec % 1000 >= 500) {
        ++micros;
    }
    printf("Microseconds: %"PRId64"\n",micros);
    return micros;
}

void main()
{
    long i, j, c, root, temp;

    printf("Start Heap ");
    start = printHeapTime();
 
    for (i = 0; i < N; i++)
       heap[i] = rand()%1000;
    for (i = 1; i < N; i++)
    {
        c = i;
        do
        {
            root = (c - 1) / 2;             
            if (heap[root] < heap[c]) 
            {
                temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            c = root;
        } while (c != 0);
    }
 
    for (j = N - 1; j >= 0; j--)
    {
        temp = heap[0];
        heap[0] = heap[j]; 
        heap[j] = temp;
        root = 0;
        do 
        {
            c = 2 * root + 1; 
            if ((heap[c] < heap[c + 1]) && c < j-1)
                c++;
            if (heap[root]<heap[c] && c<j)  
            {
                temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            root = c;
        } while (c < j);
    }

    printf("End Bubble ");
   end = printHeapTime();
   
   timeElapsed =  end - start;
   printf("Heap total : %"PRId64" microseconds , %f seconds\n", timeElapsed, (double)timeElapsed/1000000);

    
}