#include <fstream>
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

int *countingSort(int *A, int n, int *minMax, ofstream &out) {
  int min = findMinMax(A, n, minMax)[0];
  int max = findMinMax(A, n, minMax)[1];
  int range = 0;
  range = (max - min) + 1;
  int *b = new int[n];
  int *c = new int[range];

  for (int i = 0; i < range; i++) c[i] = 0;
  for (int i = 0; i < n; i++) c[A[i] - min]++;
  for (int i = 1; i < range; i++) c[i] += c[i - 1];
  out << "0 ";
  for (int i = 0; i < range - 1; i++) out << c[i] << " ";

  for (int i = n - 1; i >= 0; i--) {
    b[c[A[i] - min] - 1] = A[i];
    c[A[i] - min]--;
  }

  return b;
}

void load(ifstream &in, int size, int *v) {
  int value;

  for (int i = 0; i < size; i++) {
    in >> value;
    v[i] = value;
  }
}

void operations(ofstream &out, int *minMax, int size, int *v) {
  int *b = new int[size];
  b = countingSort(v, size, minMax, out);
  for (int i = 0; i < size; i++) out << b[i] << " ";
  out << endl;
}

int main() {
  ifstream in("input.txt");
  ofstream out("output.txt");

  string tValue;
  int size;
  int minMax[2];
  for (int i = 0; i < 100; i++) {
    minMax[0] = 99999;
    minMax[1] = 0;
    in >> size;
    int *v = new int[size];

    load(in, size, v);
    operations(out, minMax, size, v);
  }
}