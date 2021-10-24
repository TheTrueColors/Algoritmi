#include <fstream>
#include <iostream>
#include <sstream>

#include "MinHeap.h"

using namespace std;

// Funzione template per il caricamento dei valori da file all'interno dell
// vettore da passare all heap
template <typename T>
void load(ifstream& in, int size, MinHeap<T>* heap) {
  for (int i = 0; i < size; i++) {
    T value;
    in >> value;
    heap->enqueue(value);
  }
}

// Funzione template per effettuare le operazioni di passaggio del vettore e di
// stampa dell heap su file
template <typename T>
void operation(ifstream& in, ofstream& out, int size) {
  MinHeap<T>* mHeap = new MinHeap<T>(size);
  load<T>(in, size, mHeap);
  mHeap->buildHeap();
  mHeap->print(out);
  out << endl;

  delete mHeap;
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
      operation<int>(in, out, size);
    }

    if (tValue == "bool") {
      operation<bool>(in, out, size);
    }

    if (tValue == "double") {
      operation<double>(in, out, size);
    }

    if (tValue == "char") {
      operation<char>(in, out, size);
    }
  }
}