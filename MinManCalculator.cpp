#include <iostream>
#include <vector>
#include <float.h>
using namespace std;

int main()
{
    double loss1H[5] = {3.1, 3.4, 2.1, 0.0, 0.0};
    double loss1V[5] = {3.6, 2.7, 3.7, 0.0, 0.0};
    double loss2H[5] = {3.3, 4.0, 2.1, 0.0, 0.0};
    double loss2V[5] = {3.4, 1.4, 2.4, 0.0, 0.0};
    
    int unitsize = 5;
    double threshold = 0.0000001;
    vector<vector<double>> values;
    
    vector<double> unit1H;
    for(int i=0; i<unitsize; i++){
        if(loss1H[i] > threshold)
            unit1H.push_back(loss1H[i]);
    }
    values.push_back(unit1H);
    
    vector<double> unit1V;
    for(int i=0; i<unitsize; i++){
        if(loss1V[i] > threshold)
            unit1V.push_back(loss1V[i]);
    }
    values.push_back(unit1V);
    
    
    vector<double> unit2H;
    for(int i=0; i<unitsize; i++){
        if(loss2H[i] > threshold)
            unit2H.push_back(loss2H[i]);
    }
    values.push_back(unit2H);
    
    vector<double> unit2V;
    for(int i=0; i<unitsize; i++){
        if(loss2V[i] > threshold)
            unit2V.push_back(loss2V[i]);
    }
    values.push_back(unit2V);

    double min = DBL_MAX, max = 0;
    for(int i=0; i<values.size(); i++){
        for(int j=0; j<values[i].size(); j++){
            if(min > values[i][j])
                min = values[i][j];
            if(max < values[i][j])
                max = values[i][j];
        }
    }
    cout << "min: " << min << " and max: " << max;

    return 0;
}
