#include <fstream>
#include <iostream>
#include <sstream>

#include "MaxHeap.h"

using namespace std;

// Funzione template per il caricamento dei valori da file all'interno dell
// vettore da passare all heap
template <typename T>
void load(ifstream& in, int size, MaxHeap<T>* heap) {
  T value;
  string op;

  for (int i = 0; i < size; i++) {
    in >> op;
    if (op == "extract") {
      heap->extractMax();
    } else {
      if (typeid(T) == typeid(int)) value = stoi(op.substr(2, op.length()));
      if (typeid(T) == typeid(bool)) {
        if (op[2] == '1') value = true;
        if (op[2] == '0') value = false;
      }
      if (typeid(T) == typeid(double)) value = stod(op.substr(2, op.length()));
      if (typeid(T) == typeid(char)) value = op[2];
      heap->enqueue(value);
    }
  }
}

// Funzione template per effettuare le operazioni di passaggio del vettore e di
// stampa dell heap su file
template <typename T>
void operation(ifstream& in, ofstream& out, int size) {
  MaxHeap<T>* mHeap = new MaxHeap<T>(size);
  load<T>(in, size, mHeap);
  out << mHeap->hCall() << " ";
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