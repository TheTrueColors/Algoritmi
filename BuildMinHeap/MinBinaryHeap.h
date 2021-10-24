// Classe MaxBinaryHeap che eredità la classe di un BinaryHeap generico

#ifndef MaxBinaryHeap_H
#define MaxBinaryHeap_H

#include <iostream>

#include "BinaryHeap.h"
using namespace std;

template <class T>
class MinBinaryHeap : public BinaryHeap<T> {
 public:
  // Definizione del costruttore avendo solo la size, che richiama  il
  // costruttore di BinaryHeap
  MinBinaryHeap(int size) : BinaryHeap<T>(size) {}
  // Definizione del costruttore avendo un array pieno e la sua size, che
  // richiama  il costruttore di BinaryHeap
  MinBinaryHeap(T** A, int size) : BinaryHeap<T>(A, size) {}

  // Dichiarazione della funzione virtual per il confronto tra elementi del
  // vettore
  virtual double compare(T* a, T* b) = 0;
  // Dichiarazione della funzione virtual per la stampa
  virtual void printKey(int i, ofstream& out) const = 0;

  // Definizione della funzione per estrarre il Massimo
  T* extractMin() { return BinaryHeap<T>::extract(); }
  // Definizione della funzione per aumentare la key
  void increaseKey(int i, T k) { return BinaryHeap<T>::modify(i, k); }
};

#endif