// Classe  Max Heap

#ifndef MaxHeap_H
#define MaxHeap_h

#include <iostream>

#include "MaxBinaryHeap.h"

using namespace std;

template <class T>
class MaxHeap : public MaxBinaryHeap<T> {
 public:
  // Definizione della funzione virtual per il confronto tra elementi del
  // vettore
  double compare(T* a, T* b) { return (*a) - (*b); }

  // Definizione della funzione virtual di stampa
  void printKey(int i, ofstream& out) const {
    out << *(this->getPriorityQueue())[i] << " ";
  }

  // Definizione del costruttore avendo solo la size, che richiama  il
  // costruttore di MaxBinaryHeap
  MaxHeap(int size) : MaxBinaryHeap<T>(size) {}
  // Definizione del costruttore avendo un array pieno e la sua size, che
  // richiama  il costruttore di MaxBinaryHeap
  MaxHeap(T** A, int size) : MaxBinaryHeap<T>(A, size) {}
};
#endif