#include <iostream>
#include "Vector.h"
#include "Matrix.h"
#include <cstdlib>
const int rows = 10;
int main(){
    TMatrix<int> array(rows);
    for (int i = 0; i < rows; i++)
        for (int j = i; j < rows; j++)
            array[i][j] = rand() % 10;

    int tmp = 0;
    for (int i = 0; i < rows; i++)
        for (int j = i; j < rows; j++)
            if (tmp < array[i][j])
                tmp = array[i][j];
  
    cout << "max element : " << endl << tmp << endl;
   
    return 0;


}
