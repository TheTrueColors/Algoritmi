#include <fstream>
#include <iostream>
#include <sstream>

#include "MinHeap.h"

using namespace std;

// Funzione template per il caricamento dei valori da file all'interno dell
// vettore da passare all heap
template <typename T>
void load(ifstream& in, int size, T** v) {
  T value;
  string op;

  for (int i = 0; i < size; i++) {
    in >> op;
    if (typeid(T) == typeid(int)) value = stoi(op);
    if (typeid(T) == typeid(bool)) {
      if (op[0] == '1') value = true;
      if (op[0] == '0') value = false;
    }
    if (typeid(T) == typeid(double)) value = stod(op);
    if (typeid(T) == typeid(char)) value = op[0];
    v[i + 1] = new T(value);
  }
}

// Funzione template per effettuare le operazioni di passaggio del vettore e di
// stampa dell heap su file
template <typename T>
void operation(ifstream& in, ofstream& out, int size) {
  T** tmp = new T*[size + 1];
  load<T>(in, size, tmp);
  MinHeap<T>* mHeap = new MinHeap<T>(tmp, size);
  mHeap->buildHeap();
  mHeap->sort();
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