#include <iostream>

void matmul(int A[3][3], int B[3][3]){
  int res[3][3];
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      res[i][j] = 0;
      for(int k = 0; k < 3; k++){
        res[i][j] += res[i][k]*B[k][j];
      }
    }
  }
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      std::cout << res[i][j] << " ";
    }
    std::cout << '\n';
  }
}


int main(int argc, char* argv[]){
  int A[3][3] = {{1, 2, 3}, {5, 6, 7}};
  int B[3][3] = {{7, 6, 5}, {3, 2, 1}};
  int res[3][3] = {{0, 0, 0}, {0, 0, 0}};
  matmul(A, B);
  return 0;
}