// Classe che implementa una coda a priorità

#ifndef PriorityQueue_H
#define PriorityQueue_H

#include <iostream>
using namespace std;
template <class T>
class PriorityQueue {
 public:
  // Definizione metodo virtual per l'estrazione del max/min
  virtual T* extract() = 0;
  // Definizione del metodo virtual enqueue per l'inserimento di un valore
  virtual PriorityQueue<T>* enqueue(T x) = 0;
  // Definizione del metodo virtual compare per il confronto tra due elementi
  virtual double compare(T* a, T* b) = 0;
  // Definizione del metodo virtual per la stampa
  virtual void printKey(int i, ofstream& out) const = 0;
};

#endif