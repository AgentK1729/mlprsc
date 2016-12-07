/*
 * C Program to sort an array based on heap sort algorithm(MAX heap)
 */ 
#include <stdio.h>

#define N 2500
 
int heap[N];

void main()
{
    int i, j, c, root, temp;
 
    for (i = 0; i < N; i++)
       heap[i] = rand()%1000;
    for (i = 1; i < N; i++)
    {
        c = i;
        do
        {
            root = (c - 1) / 2;             
            if (heap[root] < heap[c])   /* to create MAX heap array */
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
        heap[0] = heap[j];    /* swap max element with rightmost leaf element */
        heap[j] = temp;
        root = 0;
        do 
        {
            c = 2 * root + 1;    /* left node of root element */
            if ((heap[c] < heap[c + 1]) && c < j-1)
                c++;
            if (heap[root]<heap[c] && c<j)    /* again rearrange to max heap array */
            {
                temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            root = c;
        } while (c < j);
    }
    
}