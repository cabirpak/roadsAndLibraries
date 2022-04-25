#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> rotatedMatrixPoints(int w, int h){
    vector<vector<int>> result;
    int x=h-1;
    int y=0;
    int rowlen = w;
    for(int r = 0; r<2*h-1; r++){
        if(r%2 == 0){
            rowlen = w;
        }
        else{
            rowlen = w-1;
        }
        
        for(int i=0; i<rowlen; i++){
            vector<int> p({x+i, y+i});
            result.push_back(p);
            //cout << x+i << ", " << y+i << endl;
        }
        
        if(r%2 == 0){
            
            y++;
        }
        else{
            x--;
        }
    }
    return result;
}
int main()
{
    int w = 3;
    int h = 2;
    int ContainerMatrixW = 4;
    int ContainerMatrixH = 4;
    int rotatedMatrixLen = w+h-1;
    
    vector<vector<int>> rotatedMatrix1 = rotatedMatrixPoints(w,h);
    vector<vector<int>> rotatedMatrix2 = rotatedMatrixPoints(h,w);
    
    for(int sx=0; sx+rotatedMatrixLen<=ContainerMatrixW; sx++)
        for(int sy=0; sy+rotatedMatrixLen<=ContainerMatrixH; sy++){
            cout << "rotated left sx:" << sx << " sy:" << sy << endl;
            for(vector<int> r:rotatedMatrix1){
                for(int p:r){
                    cout << p << ", ";
                }
                cout << endl;
            }
            
            cout << "rotated right sx:" << sx << " sy:" << sy << endl;
            for(vector<int> r:rotatedMatrix2){
                for(int p:r){
                    cout << p << ", ";
                }
                cout << endl;
            }
        }

    return 0;
}
