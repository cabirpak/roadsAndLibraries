#include <stdio.h>
#include <stdlib.h>
#define NUMBER_OF_ARRAYS 4
#define ARRAY_SIZE 5
int main()
{
    double loss1H[ARRAY_SIZE] = {3.1, 3.4, 2.1, 0.0, 0.0};
    double loss1V[ARRAY_SIZE] = {3.6, 2.7, 3.7, 0.0, 0.0};
    double loss2H[ARRAY_SIZE] = {3.3, 4.0, 2.1, 0.0, 0.0};
    double loss2V[ARRAY_SIZE] = {3.4, 1.4, 2.4, 0.0, 0.0};
    
    double threshold = 0.01;
    
    double min1H = 9999.0, max1H = 0;
    
    for(int j=0; j<ARRAY_SIZE; j++){
        if(loss1H[j] > threshold){
            if(min1H > loss1H[j])
                min1H = loss1H[j];
            if(max1H < loss1H[j])
                max1H = loss1H[j];
        }
    }
    printf("loss1H --> min: %lf and max: %lf\n", min1H, max1H);
    
    double min1V = 9999.0, max1V = 0;
    
    for(int j=0; j<ARRAY_SIZE; j++){
        if(loss1V[j] > threshold){
            if(min1V > loss1V[j])
                min1V = loss1V[j];
            if(max1V < loss1V[j])
                max1V = loss1V[j];
        }
    }
    printf("loss1V --> min: %lf and max: %lf\n", min1V, max1V);

    double min2h = 9999.0, max2h = 0;
    
    for(int j=0; j<ARRAY_SIZE; j++){
        if(loss2H[j] > threshold){
            if(min2h > loss2H[j])
                min2h = loss2H[j];
            if(max2h < loss2H[j])
                max2h = loss2H[j];
        }
    }
    printf("loss2H --> min: %lf and max: %lf\n", min2h, max2h);
    
    double min2v = 9999.0, max2v = 0;
    
    for(int j=0; j<ARRAY_SIZE; j++){
        if(loss2V[j] > threshold){
            if(min2v > loss2V[j])
                min2v = loss2V[j];
            if(max2v < loss2V[j])
                max2v = loss2V[j];
        }
    }
    printf("loss2V --> min: %lf and max: %lf\n", min2v, max2v);

    
    double min = 9999.0, max = 0;
    if(min > min1H)
        min = min1H;
    if(min > min1V)
        min = min1V;
    if(min > min2h)
        min = min2h;
    if(min > min2v)
        min = min2v;
        
    if(max < max1H)
        max = max1H;
    if(max < max1V)
        max = max1V;
    if(max < max2h)
        max = max2h;
    if(max < max2v)
        max = max2v;

    printf("whole --> min: %lf and max: %lf\n", min, max);
    
    return 0;
}
