#include <iostream>

using namespace std;
int *findMinMax(int *A, int n, int *minMax) {
  for (int i = 0; i < n; i++) {
    if (A[i] < minMax[0])
      minMax[0] = A[i];
    else if (A[i] > minMax[1])
      minMax[1] = A[i];
  }
  return minMax;
}

int *countingSort(int *A, int n, int *minMax) {
  int min = findMinMax(A, n, minMax)[0];
  int max = findMinMax(A, n, minMax)[1];
  int range = max - min + 1;
  int *b = new int[n];
  int *c = new int[range];

  for (int i = 0; i < range; i++) c[i] = 0;
  for (int i = 0; i < n; i++) c[A[i] - min]++;
  for (int i = 1; i < range; i++) c[i] += c[i - 1];
  for (int i = n - 1; i >= 0; i--) {
    b[c[A[i] - min] - 1] = A[i];
    c[A[i] - min]--;
  }
  return b;
}

int main() {
  int A[8] = {6, 5, 5, 3, 4, 6, 3, 5};
  int n = 8;
  int minMax[2] = {9999, 0};

  int *B = new int(n);

  B = countingSort(A, n, minMax);

  for (int i = 0; i < n; i++) cout << B[i] << " ";
}