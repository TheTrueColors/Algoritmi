#include <fstream>
#include <iostream>
#include <sstream>

#include "MinHeap.h"

using namespace std;

// Funzione template per il caricamento dei valori da file all'interno dell
// vettore da passare all heap
template <typename T>
void load(T** v, ifstream& in, int size) {
  for (int i = 0; i < size; i++) {
    T value;
    in >> value;
    v[i + 1] = new T(value);
  }
}

// Funzione template per effettuare le operazioni di passaggio del vettore e di
// stampa dell heap su file
template <typename T>
void operation(T** v, ofstream& out, int size) {
  MinHeap<T>* mHeap = new MinHeap<T>(v, size);

  mHeap->buildHeap();
  mHeap->print(out);
  out << endl;

  delete mHeap;
  delete[] v;
}

int main() {
  ifstream in("input.txt");
  ofstream out("output.txt");

  string tValue;
  int size;

  for (int i = 0; i < 100; i++) {
    in >> tValue;
    in >> size;

    if (tValue == "int") {
      int** v = new int*[size + 1];
      load<int>(v, in, size);
      operation<int>(v, out, size);
    }

    if (tValue == "bool") {
      bool** v = new bool*[size + 1];
      load<bool>(v, in, size);
      operation<bool>(v, out, size);
    }

    if (tValue == "double") {
      double** v = new double*[size + 1];
      load<double>(v, in, size);
      operation<double>(v, out, size);
    }

    if (tValue == "char") {
      char** v = new char*[size + 1];
      load<char>(v, in, size);
      operation<char>(v, out, size);
    }
  }
}