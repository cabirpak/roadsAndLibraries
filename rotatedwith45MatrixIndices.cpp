#include <iostream>
#include <vector>
using namespace std;

vector < vector < int >> rotatedMatrixIndices (int width, int height){
  vector < vector < int >> indices;
  int r = 0;
  int x=height-1, y=0;
  
  while(r < 2*height-1){
      int w = width;
      if(r%2 != 0)
        w--;
        
      for(int i=0; i<w; i++){
          vector<int> pos({x+i, y+i});
          indices.push_back(pos);
      }
        
      r++;
      if(r%2==0){
          x--;
      }else{
          y++;
      }
  }
  return indices;
}

void printIndices(vector < vector < int >>result){
    cout << "--------------------------" << endl;
  for (int i = 0; i < result.size (); i++){
      for (int j = 0; j < result[0].size (); j++)
        cout << result[i][j] << ", ";
      cout << endl;
    }
}

int main (){
  cout << "Hello World" << endl;
  int matrix_w=4, matrix_h=5;
  int w=3, h=2;
  
  vector < vector < int >> rotatedIndices1 = rotatedMatrixIndices (w, h);
  vector < vector < int >> rotatedIndices2 = rotatedMatrixIndices (h, w);
  
  int rotated_size = w+h-1;
  for(int shiftx=0; shiftx<=matrix_w-rotated_size; shiftx++)
      for(int shifty=0; shifty<=matrix_h-rotated_size; shifty++){
          cout << "shiftx:" << shiftx << " shifty:" << shifty << endl;
        vector < vector < int >> result1 = rotatedIndices1;
        for(int i=0; i<result1.size(); i++){
            result1[i][0] += shiftx;
            result1[i][1] += shifty;
        }
        printIndices(result1);
        
        result1 = rotatedIndices2;
        for(int i=0; i<result1.size(); i++){
            result1[i][0] += shiftx;
            result1[i][1] += shifty;
        }
        printIndices(result1);
      }
  return 0;
}
