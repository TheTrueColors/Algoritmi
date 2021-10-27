// Classe  Max Heap

#ifndef MaxHeap_H
#define MaxHeap_h

#include <iostream>

#include "MinBinaryHeap.h"

using namespace std;

template <class T>
class MinHeap : public MinBinaryHeap<T> {
 public:
  // Definizione della funzione virtual per il confronto tra elementi del
  // vettore
  double compare(T* a, T* b) { return (*b) - (*a); }

  // Definizione della funzione virtual di stampa
  void printKey(int i, ofstream& out) const {
    out << *(this->getPriorityQueue())[i] << " ";
  }

  // Definizione del costruttore avendo solo la size, che richiama  il
  // costruttore di MaxBinaryHeap
  MinHeap(int size) : MinBinaryHeap<T>(size) {}
  // Definizione del costruttore avendo un array pieno e la sua size, che
  // richiama  il costruttore di MaxBinaryHeap
  MinHeap(T** A, int size) : MinBinaryHeap<T>(A, size) {}
};
#endif