#include <stdio.h>
#include <stdlib.h>
//#include <float.h>
#define NUMBER_OF_ARRAYS 4
#define ARRAY_SIZE 5
int main()
{
    /*int *x;
    
    x = malloc(3*sizeof(int));
    
    *x = 5;
    
    printf("%d\n", *x);
    
    free(x);
    
    
    *x = 6;
    
    printf("%d\n", *x);
    
    if(1)
        return 0;*/
    
    double loss1H[ARRAY_SIZE] = {3.1, 3.4, 2.1, 0.0, 0.0};
    double loss1V[ARRAY_SIZE] = {3.6, 2.7, 3.7, 0.0, 0.0};
    double loss2H[ARRAY_SIZE] = {3.3, 4.0, 2.1, 0.0, 0.0};
    double loss2V[ARRAY_SIZE] = {3.4, 1.4, 2.4, 0.0, 0.0};
    
    double threshold = 0.01;
    //statically constructed array of array instead of allocating dynamically by malloc
    double values[NUMBER_OF_ARRAYS][ARRAY_SIZE];
    
    for(int i=0; i<ARRAY_SIZE; i++)values[0][i] = loss1H[i];
    for(int i=0; i<ARRAY_SIZE; i++)values[1][i] = loss1V[i];
    for(int i=0; i<ARRAY_SIZE; i++)values[2][i] = loss2H[i];
    for(int i=0; i<ARRAY_SIZE; i++)values[3][i] = loss2V[i];
    
    double min = 999999.0, max = 0;
    for(int i=0; i<NUMBER_OF_ARRAYS; i++){
        for(int j=0; j<ARRAY_SIZE; j++){
            if(values[i][j] > threshold){
                if(min > values[i][j])
                    min = values[i][j];
                if(max < values[i][j])
                    max = values[i][j];
            }
        }
    }
    printf("min: %lf and max: %lf", min, max);

    /*for(int i=0; i<NUMBER_OF_ARRAYS; i++){
        free(values[i]);
    }*/
    //free(values);

    return 0;
}
