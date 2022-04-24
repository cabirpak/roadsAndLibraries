#include <iostream>
#include <vector>
#include <float.h>
using namespace std;
#define NUMBER_OF_ARRAYS 4
#define ARRAY_SIZE 5
int main()
{
    double loss1H[ARRAY_SIZE] = {3.1, 3.4, 2.1, 0.0, 0.0};
    double loss1V[ARRAY_SIZE] = {3.6, 2.7, 3.7, 0.0, 0.0};
    double loss2H[ARRAY_SIZE] = {3.3, 4.0, 2.1, 0.0, 0.0};
    double loss2V[ARRAY_SIZE] = {3.4, 1.4, 2.4, 0.0, 0.0};
    
    double threshold = 0.0000001;
    double **values = (double**)malloc(NUMBER_OF_ARRAYS*sizeof(double*));
    
    values[0] = loss1H;
    values[1] = loss1V;
    values[2] = loss2H;
    values[3] = loss2V;

    double min = DBL_MAX, max = 0;
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
    cout << "min: " << min << " and max: " << max;

    return 0;
}
