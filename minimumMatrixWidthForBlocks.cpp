#include <iostream>
#include <vector>
using namespace std;

/*
given a blocks sizes within a vector named blocks and a height for the matrix for inserting the blocks,
find a minimum width for the matrix.

if blocks={1,3,3,3} and height=2;
then, 
matrix=1,3
       3,3
so, the minimum width is 6.

if blocks={3} and height=1;
then,
matrix={3}
so the minimum width is 3.

*/

int solution(vector<int> blocks, int height) {
    int total = 0;
    for(int i=0; i<blocks.size(); i++)
        total += blocks[i];
    for(int cols=1; cols<=total; cols++){
        int rowtotal = 0;
        int rows = 0;
        int j=0;
        for(; j<blocks.size(); j++){
            if(blocks[j] > cols)
                break;
            if(rowtotal + blocks[j] > cols){
                rows ++;
                if(rows >= height)
                    break;
                rowtotal = 0;
            }
            rowtotal += blocks[j];
        }
        if(rows < height && j==blocks.size())
            return cols;
    }
    return -1;
}

int main()
{
    cout<<"Hello World" << solution(vector<int>({3}), 1);

    return 0;
}
