#include <stdio.h>
#include <stdlib.h>
#include "quicksort.h"
#include "binarySearch.h"

void trSort(float v[], int n){

        float *w;
        w = malloc(sizeof(float)*n);

        int i;
        for (i = 0; i< n; i++)
                w[i] = v[i];

        quicksort(w, 0, n-1);
        
        for (i = 0; i < n; i++)
                printf("%.f ", w[i]);

}



int main(int argc, char const *argv[])
{
        float v[] = {1,2,4,5,78,41,4,4,2,741,1};

        trSort(v, 10);
}